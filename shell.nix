{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "cpp project";
  buildInputs = with pkgs; [
    pkgsCross.mingwW64.buildPackages.gcc
  ];
  
  shellHook = ''
   echo "C++ development shell";
  '';
}
