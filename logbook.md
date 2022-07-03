# Logbook
I'll register everything learned through the project. I'll try very hard to update it weekly with what I'd done in this timeframe.

# Week #01
## What is this project about?
The PDF starts with a lesson history about [*Ghosts'n Goblins*](https://en.wikipedia.org/wiki/Ghosts_%27n_Goblins_(video_game)), a major commercial success across arcades and home systems side-scrolling platform game relesed for arcades in 1985. The game is often considered very difficult by arcade standards and is commonly regarded as **one of the most difficult games ever released.**

The FdF project is about creating a simple wireframe model representation of a 3D landscape. I mentioned the project with friends, and seems the project is similar to [Point Cloud](https://en.wikipedia.org/wiki/Point_cloud/).

A point cloud is essensually the simplest form of a 3D  model. It is a collection of individual points plotted in 3D space. Each point contains several measurements including its cordinates along the X, Y and Z axis, and sometimes additonal data as color value, which is stored in RGB format and luminance value which determines how bright the point is.

FdF is short for *Fil der Fer* meaning in frech *Wireframe Model*.

This will be my first **graphic** project, so I need to familiarize with the **MiniLibX**, an internally library that includes the basic to create interface and deal with keyboard and mouse events.

## VNC
Since the project requires an interface I discovered that I need to use a VNC in order to make it work. So what is a VNC?

VNC stands for Virtual Network Computing. It is a cross-platform screen sharing system that was created to remotely control another computer using [Remote Frame Buffer protocol](https://en.wikipedia.org/wiki/RFB_protocol/). It transmits the keyboard and mouse input from one computer to another, replaying the graphical-screen updates, over network.

[Read more](http://www.remoteaccess.org/what-is-a-vnc/)

Since I can't refuse an easy way of doing things, and the school already offers a connection using [TightVNC](https://www.tightvnc.com/) this is the program I'll use for now on.

## MiniLibX
The [MiniLibX](https://github.com/42Paris/minilibx-linux/) provided  is what I will use to make windows, their behaviors like when the user press a button and what should be displayed.

I will use the Linux distribution since this is the enviroment provided by [42SP](https://www.42sp.org.br/).

The first thing to do is clone or download the MiniLibX repository into the root of my project.

```
git clone https://github.com/42Paris/minilibx-linux
```

As the **README.md** says to make it work I just need to execute the `configure` script.

```
bash configure
```

To compile the files I want some flags are needed.

```
cc *file_name.c* -Lminilibx_linux -lmlx_Linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz
```

`-I`*dir* Search *dir* for included files whose names do not begin with `/` before searching the usual directories.

`-L`*dir* While compiling *source_file.c* searches for header files in the specified directory.

`-l`*library* Adds the indicated library to the list of libraries to be linked. [Read more about **Compiler Options**](https://docs.oracle.com/cd/E19957-01/806-3567/cc_options.html)

`-lXext` The X Extensions library provides mechanisms that were not provided in the core protocol in Xlib. [Read more about **Xext**](http://osr507doc.sco.com/en/man/html.Xext/Intro.Xext.html/)

`-lX11` Allow VNC connections to real X11 displays [Read more about **X11** ](https://www.manpagez.com/man/3/X11::Protocol::Ext::XFIXES/)

`-lm` To `#include <math.h>` [Read more about **math**](https://linux.die.net/man/3/math/)

`-lz` To `#include <zlib.h>` [Read more about **zlib**](https://linux.die.net/man/3/zlib/)