## Cub3D

A game project for school 21, campus of Ecole 42. A first person 3D representation of a maze, using raycasting technoligies.  
The project is inspired by Wolfenstein3D, implemented in C. It runs using the MiniLibX, a simplified version of the Xlib, created by a team of the school for educational purposes. It uses a version of MiniLibX for Linux.

### Usage

This version is only available for Linux.  
Run `make bonus` in the project directory to create an executable.  
Then `./cub3D_bonus ./map/example.cub` to run the game.

### About the project

You can move around the maze using ↑ and ↓ arrows or W A S D keys; to rotate use ← and →. Also it is possible to rotate a point of view with a mouse.
To exit press on the red cross of the window or an ESC button.

![screenshot_1](/.screenshot/screenshot1.jpg)

The game requires a configuration file in .cub format. There are a few maps in the ./map directory with different map structures and textures. They can be adjustde and modified as you need. There are several requirements for the map to be considered to be valid; but don't worry! If something goes wrong, the programm will print a message, saying what exactly isn't well.  
In a nutshell: `NO SO WE EA` keys mean textures for different sides of the map; `C F` colors of a ceiling and a floor in RGB format; and then goes a map, where `1` is a representation of a wall, and `0` - of an empty space.  

### Credit

The project was done in team with [hashly](https://github.com/hashlyschool).  
My part of the project was - parser, textures, keys handling; and my teammate handled raycasting algorithm.
