{
  description = "Exercícios resolvidos.";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/master";
  outputs =
    { nixpkgs, ... }:
    let
      inherit (nixpkgs) lib;
      forAllSystems = lib.genAttrs lib.systems.flakeExposed;
    in
    {
      devShells = forAllSystems (
        system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
          emacsSettings = pkgs.writeText "dir-locals.el" ''
            ((nil . ((eval . (with-eval-after-load 'apheleia
                       (add-to-list 'apheleia-formatters
                         '(verible . ("verible-verilog-format" "--inplace" filepath)))))))
             (verilog-mode . ((apheleia-formatter . (verible))
                              (eglot-server-programs . ((verilog-mode . ("verible-verilog-ls"))))))
             (verilog-ts-mode . ((apheleia-formatter . (verible))
                                 (eglot-server-programs . ((verilog-mode . ("verible-verilog-ls")))))))
          '';
        in
        {
          default = pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
            packages = with pkgs; [
              asmfmt
              cargo
              clang-tools
              iverilog
              jdk25_headless
              jdt-language-server
              nixd
              nixfmt
              nodejs
              rars
              rassumfrassum
              rustc
              uv
              verible
              vtsls
            ];
            shellHook = ''
              ln -sf ${emacsSettings} .dir-locals.el
            '';
          };
        }
      );
    };
}
