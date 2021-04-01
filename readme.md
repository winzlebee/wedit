# Win Engine

Just a quick 3d editor that can run as a game engine

## To Build

Install *gtkmm-3.0*, *OpenGL*, *Glew* and *glm* using your distribution.

These are the only dependencies. The game engine sits atop the graphics driver as directly as possible.

Then;

1. `mkdir build && cd build`
2. `cmake ../`
3. `make`