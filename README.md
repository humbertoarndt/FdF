# FdF
![preview_gif](/images/preview_fdf.gif)
*Visualizing "t1.fdf" in 3D.*

## About
Fdf (in franch *'fil de fer'*, meaning 'wireframe model') is about representing a landscape as a 3D object in which all surfaces are outlined in lines. The coordinates of this landscape are stored in a file passe as a parameter to your program. Here is an example:

```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Each number corresponds to a point in space:
• **x**: The horizontol position corresponds to its axis.
• **y**: The vertical position corresponds to its ordinate.
• **z**: The value corresponds to its altitude.

Wich render in Fdf:
![42](/images/preview_42.png)

## Implementation

### Drawing a line

At 42SP we are forced to do everything from the scratch. In this case it meant that we weren't given any line drawing function so we had to figure ourselves how to color pixels between line endpoints with help of [miniLibX library](https://qst0.github.io/ft_libgfx/man_mlx.html
). I used [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) for drawing a line which was the most obvious choice.

### Projections

In this project we must have 2 type of projection but we were free to choose the type of projection:
parallel, iso, conic.

I chose to use isometric and conic. Also I added dimetric projections which was very easy to implement from isometric projection (30 degree angle -> 15).

## Controls

I have the following controls to help user to view different maps:

• Rotation around the axis: Arrow Keys
• Change projections: 1 = ISO 2 = DIMETRIC 3 = CONIC
• Zooming in and out: Mouse sroll
• Moving the map on the screen: Right click
• Change color mode:: 'C' key
• Reset map values: 'D' key

Using graphic library: miniLibX
https://qst0.github.io/ft_libgfx/man_mlx.html