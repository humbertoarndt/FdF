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

# Week #02
Talking with veterans at 42SP I discovered that, for now, I can compile my tests using just 

```
cc my_file.c -lmlx lXext -lX11
```

I did some tests, and since the enviroment already is able to use minilibx I don't really know if I need to put it in my project.

# Makefile
The minimium part of any project they say, well this time is kind hard.

**IT JUST WORK AND I CAN'T REMEMBER WHAT I DID.**

Besides the usual flags `-Wall -Werror -Wextra` I need to add the `-O3` flag, looked a bit for what it does and is for compile optimzation.

[Read more compiler comands](https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html)

# Time to learn how to use MiniLibX
## Creating a window
In order to start having some fun I create two files `fdf.h` to be used as the header for the project and a `test.c` where my code will be for now.

Before I can do anything I must include the `<mlx.h>` library in my header to access all the MiniLibX functions.

```c
#include <mlx.h>
```

`mlx_init()` is the first function I'll use. It will stablish a connection between the program I am creating and the display. No parameters are needed, and it will return an address `void*` useful to further call in the MiniLibX.

```c
#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
}
```

The only thing done was to initiate the `mlx` so no window pops up yet. To make it happens a window must be initialized and I'll do that using the `mlx_new_window()` function, which will also returns a pointer `void*` to the window created. This function receive the pointer to mlx, values to width and height, and a title. Then I'll call `mlx_loop()` function so my window can stays opened until I interrupt the process (`Ctrl+C`).

```c
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 300, "My first window");
	mlx_loop(mlx);
}
```