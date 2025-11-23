#!/bin/bash
#Some BS
echo ("Hello Sexy Boy! Are you single and alone?
Good Try this framwork. IT's not complicated
It's justaGuiFramework")

#Installing dependencies
sudo pacman -S base-devel
sudo pacman -S cmake
sudo pacman -S gtk

#Building the actual C Program or complin it ig
cd build
cmake ..
cmake --build .