# Cub3d

This cub3d is coded in C and runs on Linux 🐧  
It simulates a 3D enviroment using raycasting techniques.

For the mandatory part, do
```
make
./cub3D maps/map1.cub
```

For the bonus part, do
```
make bonus
./cub3D maps/bonusmap1.cub
```

## Player's Guide

Use WASD to move through the maze.  
Use left and right arrow keys to rotate.  
Beware of sprites!

![cub3d](https://github.com/user-attachments/assets/4bc7ebcd-3f20-41aa-be95-2776da4a17b6)

## Map Example

### maps/map.cub

```
NO	./textures/north.xpm 
SO  ./textures/south.xpm 
WE  ./textures/west.xpm
EA  ./textures/east.xpm

=> change texture file above for each direction

F 25, 0, 215
C 10, 25, 16

=> change floor (F) and ceiling (C) RGB color

11111111
10000001
10010001
100N1001
10010001
10000001
11111111

=> map structure : 0 for free area, 1 for a wall, N for player
```



