/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:33:23 by harndt            #+#    #+#             */
/*   Updated: 2022/08/04 20:28:12 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Calculates rotation in the x axys.
 * 
 * @param point 
 * @param ang 
 */
static void	rotate_x(t_points *point, double ang)
{
	int	y;

	y = point->ry;
	point->ry = y * cos(ang) + point->rz * sin(ang);
	point->rz = -y * sin(ang) + point->rz * cos(ang);
}

/**
 * @brief Calculates rotation in the y axys.
 * 
 * @param point 
 * @param ang 
 */
static void	rotate_y(t_points *point, double ang)
{
	int	x;

	x = point->rx;
	point->rx = x * cos(ang) + point->rz * sin(ang);
	point->rz = -x * sin(ang) + point->rz * cos(ang);
}

/**
 * @brief Calculates rotation in the z axys.
 * 
 * @param point 
 * @param ang 
 */
static void	rotate_z(t_points *point, double ang)
{
	int	x;
	int	y;

	x = point->rx;
	y = point->rz;
	point->rx = x * cos(ang) - y * sin(ang);
	point->ry = x * sin(ang) + y * cos(ang);
}

void	rotate(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			fdf->points[y][x]->rx = fdf->points[y][x]->px;
			fdf->points[y][x]->ry = fdf->points[y][x]->py;
			fdf->points[y][x]->rz = fdf->points[y][x]->pz;
			fdf->points[y][x]->rx *= fdf->controls->zoom;
			fdf->points[y][x]->ry *= fdf->controls->zoom;
			fdf->points[y][x]->rz *= fdf->controls->zoom / fdf->controls->zmod;
			fdf->points[y][x]->rx -= (fdf->width * fdf->controls->zoom) / 2;
			fdf->points[y][x]->ry -= (fdf->height * fdf->controls->zoom) / 2;
			rotate_x(fdf->points[y][x], radian_ang(fdf->controls->x_angle));
			rotate_y(fdf->points[y][x], radian_ang(fdf->controls->y_angle));
			rotate_z(fdf->points[y][x], radian_ang(fdf->controls->z_angle));
			x++;
		}
		y++;
	}
}
