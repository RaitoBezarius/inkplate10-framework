{
  description = "Inkplate 10 framework";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    nixpkgs-esp-dev.url = "github:mirrexagon/nixpkgs-esp-dev";
  };

  outputs = { self, nixpkgs, nixpkgs-esp-dev }: {
    devShells.x86_64-linux.default = nixpkgs-esp-dev.devShells.x86_64-linux.esp32-idf;
  };
}
