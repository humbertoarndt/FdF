/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:20:12 by harndt            #+#    #+#             */
/*   Updated: 2022/08/12 21:30:01 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// =============================================================================
// LOCAL LIBRARIES
// =============================================================================
# include "colors.h"
# include "error.h"
# include "keys.h"
# include "../libft/libft.h"

// =============================================================================
// EXTERNAL LIBRARIES
// =============================================================================
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

// =============================================================================
// WINDOW SIZE
// =============================================================================
# define W_WIDTH	1260
# define W_HEIGHT	600
# define L_WIDTH	190
# define W_NAME		"FDF - harndt"
# define ISO		1
# define DIMETRIC	2
# define CONIC		3

// =============================================================================
// STRUCTS
// =============================================================================
/**
 * @brief This struct holds the image values to be plotted on the screen.
 * 
 */
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/**
 * @brief This struct stores the controls variables.
 * 
 */
typedef struct s_ctrls
{
	double	zoom;
	double	zmod;
	int		shift_x;
	int		shift_y;
	int		color;
	int		x_angle;
	int		y_angle;
	int		z_angle;
}	t_ctrls;

/**
 * @brief This struct stores the points to plot.
 * 
 */
typedef struct s_points
{
	int		px;
	int		py;
	int		pz;
	int		color;
	int		ix;
	int		iy;
	double	rx;
	double	ry;
	double	rz;
}	t_points;

/**
 * @brief This struct stores all points read from a .fdf file.
 * 
 */
typedef struct s_fdf
{
	t_points		***points;
	t_ctrls			*controls;
	int				height;
	int				width;
	int				delta_x;
	int				delta_y;
	int				slope_x;
	int				slope_y;
	int				x;
	int				y;
	int				err;
	int				projection;
}	t_fdf;

/**
 * @brief This struct stores the pointer to mlx and window, as for
 * a t_fdf struct.
 * 
 */
typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_img	legend;
	t_fdf	*fdf;
}	t_win;

// =============================================================================
// FUNCTIONS
// =============================================================================
/**
 * @brief This function initiates the t_win struct, which stores the minilibx
 * and window pointers, as a struct t_fdf.
 * 
 * @param data The struct to be initiated.
 * @param path The path to the file that needs to be readed.
 */
void	init_mlx(t_win *data, char *path);

/**
 * @brief This function initiates the t_controls struct, which stores the
 * controls variable to use the program.
 * 
 * @return t_ctrls* Pointers where the struc is stored.
 */
t_ctrls	*init_controls(void);

/**
 * @brief This function resets all controls variables in the t_controls struct
 * 
 * @param fdf The t_fdf where the controls are.
 */
void	reset_controls(t_fdf *fdf);

/**
 * @brief Get the height object.
 * 
 * @param path The path to the file to read.
 * @return int The height from the file, count of lines contained.
 */
int		get_height(char *path);

/**
 * @brief Get the width object
 * 
 * @param path The path to the file to read.
 * @return int The width from the file, split columns by ' '.
 */
// static int	get_width(t_fdf *fdf, char **values, int n_row);
// int		get_width(char *path);

/**
 * @brief This function reads the file the gets its content.
 * 
 * @param fdf The t_fdf that will stored the file data.
 * @param path The path to the file that needs to be read.
 */
void	read_input(t_fdf	*fdf, char *path);

/**
 * @brief This function prints an error in the terminal 
 * and ends the program.
 * 
 * @param error_msg The message to be printed.
 */
void	print_error(char *error_msg);

/**
 * @brief This function draws legends in the windows about the
 *  usage of the program.
 * 
 * @param data The t_win to the opened window.
 */
void	draw_legend(t_win *data);

/**
 * @brief This function reads the key pressed by the user.
 * 
 * @param keysym The key pressed.
 * @param data The t_win where the key was pressed.
 * @return int 0 if success, 1 case the key does not exist.
 */
int		press_key(int keysym, t_win *data);

/**
 * @brief This function free all memory allocated.
 * 
 * @param data t_win that needs to be freed.
 */
void	free_all(t_win *data);

/**
 * @brief This function prints in the terminal the file read.
 * 
 * @param fdf The t_fdf where the data read from file is sotred.
 */
void	print_points(t_fdf *fdf);

/**
 * @brief This function maintains the objects on the windows.
 * 
 * @param data The t_win where the objects will be.
 * @return int Return 1.
 */
int		expose_hook(t_win *data);

/**
 * @brief Get the color object
 * 
 * @param fdf The fdf struct to read.
 * @param start The starting point.
 * @param end The ending point.
 * @return int The color to use
 */
int		get_color(t_fdf *fdf, t_points *start, t_points *end);

/**
 * @brief This functions plots the map in an image.
 * 
 * @param data The data struct where all points are stored.
 */
void	plot_map(t_win *data);

/**
 * @brief This function checks the vaues stored in the fdf struct.
 * 
 * @param fdf The fdf to check.
 */
void	check_fdf(t_fdf *fdf);

/**
 * @brief Set the color object
 * 
 * @param fdf The fdf to set color.
 * @param z The integer readed from file.
 * @return int A color.
 */
int		set_color(t_fdf *fdf, int z);

/**
 * @brief This function calculate the projection of the map.
 * 
 * @param fdf The fdf to project.
 */
void	projection(t_fdf *fdf);

/**
 * @brief Calculates the randian angle from a double.
 * 
 * @param angle The angle to calculate.
 * @return double The angle calculated.
 */
double	radian_ang(int angle);

/**
 * @brief Calculates the roation of the map.
 * 
 * @param fdf The fdf to rotate.
 */
void	rotate(t_fdf *fdf);

/**
 * @brief Controls all mouse button press.
 * 
 * @param button The button pressesed.
 * @param x The x position.
 * @param y The y position.
 * @param data The windows where the press occured.
 * @return int 1
 */
int		press_mouse(int button, int x, int y, t_win *data);

/**
 * @brief Render the background image with a color.
 * 
 * @param img The image to  render.
 * @param color The color to render.
 */
void	render_background(t_img *img, int color);

/**
 * @brief Function input pixels on the screen.
 * 
 * @param img The image to put a pixel.
 * @param x The position on the x axys
 * @param y The position on the y axys.
 * @param color The color of the pixel.
 */
void	img_pix_put(t_img *img, int x, int y, int color);

/**
 * @brief End the program by destroing and freeing every memory allocated.
 * 
 * @param data The struct to free.
 * @return int 
 */
int		end_program(t_win *data);

/**
 * @brief This function projects the fdf on the screen after moving
 * or rotating.
 * 
 * @param data The struct to project.
 */
void	reproject(t_win *data);
#endif