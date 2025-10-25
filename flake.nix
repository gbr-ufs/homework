# Este flake é impuro porque ele usa a função "currentSystem".
# Isso é melhor do que ter que depender no flake-utils, e funciona como uma
# forma de "protesto" contra a verbosidade dos flakes.

{
  description = "Exercícios resolvidos.";

  inputs = { nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable"; };

  outputs = { self, nixpkgs }:
    let
      system = builtins.currentSystem; # Impureza aqui.
      pkgs = nixpkgs.legacyPackages.${system};

    in {
      devShell.${system} = pkgs.mkShell {
        packages = with pkgs; [
          clang # Language server.
          gcc
          jdk24
          nodejs
          vtsls
        ];
      };
    };
}
