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
        in
        {
          default = pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
            packages = with pkgs; [
              cargo
              clang-tools
              jdk25_headless
              jdt-language-server
              nixd
              nixfmt
              nodejs
              python3
              ruff
              rustc
              ty
              vtsls
            ];
          };
        }
      );
    };
}
