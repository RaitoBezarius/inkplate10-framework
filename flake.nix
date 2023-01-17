{
  description = "Inkplate 10 framework";

  inputs = {
    nixpkgs.url = "nixpkgs/nixpkgs-unstable";
    nixpkgs-esp-dev.url = "github.com:mirrexagon/nixpkgs-esp-dev";
  };

  outputs = { self, nixpkgs, nixpkgs-esp-dev }: {
    devShells.default = nixpkgs-esp-dev.devShells.esp32-idf;
  };
}
