{
  description = "Inkplate 10 framework";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    nixpkgs-esp-dev.url = "github:mirrexagon/nixpkgs-esp-dev";
  };

  outputs = { self, nixpkgs, nixpkgs-esp-dev }: {
    devShells.default = nixpkgs-esp-dev.devShells.esp32-idf;
  };
}
