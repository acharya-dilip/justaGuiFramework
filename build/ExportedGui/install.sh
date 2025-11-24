#!/bin/bash


#Installing dependencies
sudo pacman -S base-devel
sudo pacman -S cmake
sudo pacman -S gtk

#Building the actual C Program or complin it ig
cd build
cmake ..
cmake --build .