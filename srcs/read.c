/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:26:21 by harndt            #+#    #+#             */
/*   Updated: 2022/08/11 01:06:42 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(t_fdf *fdf, char **values, int n_row)
{
	int	x;

	x = 0;
	while (values[x])
		x++;
	if (x == 0 || (n_row > 0 && x != fdf->width))
		print_error(MAP_ERROR);
	if (x > fdf->width)
		fdf->width = x;
	return (x);
}

/**
 * @brief Stores the values read from a pathfile in a ***array.
 * 
 * @param values The values read from pathfile.
 * @param fdf The fdf to store.
 * @param y The line being read.
 */
static void	store_values(char **values, t_fdf *fdf, int y)
{
	int	x;
	int	width;

	x = 0;
	width = get_width(fdf, values, y);
	fdf->points[y] = (t_points **)malloc(sizeof(t_points *) * (width + 1));
	if (!fdf->points[y])
		print_error(MLC_ERROR);
	while (values[x] != NULL)
	{
		fdf->points[y][x] = (t_points *)malloc(sizeof(t_points));
		if (!fdf->points[y][x])
			print_error(MLC_ERROR);
		fdf->points[y][x]->px = x;
		fdf->points[y][x]->py = y;
		if (values[x] == NULL)
			print_error(MAP_ERROR);
		fdf->points[y][x]->pz = ft_atoi(values[x]);
		free(values[x]);
		x++;
	}
	free(values);
	fdf->points[y][x] = NULL;
}

/**
 * @brief Store all lines read from pathfile.
 * 
 * @param fdf The fdf to stored values.
 * @param path The pathfile to read.
 */
static void	save_lines(t_fdf *fdf, char *path)
{
	int		i;
	int		fd;
	char	*row;
	int		n_row;
	char	**values;

	i = 0;
	row = NULL;
	n_row = fdf->height;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error(OPN_ERROR);
	while (i < n_row)
	{
		row = ft_get_next_line(fd);
		if (!row)
			print_error(GNL_ERROR);
		values = ft_split(row, ' ');
		store_values(values, fdf, i);
		free(row);
		i++;
	}
	close(fd);
	fdf->points[n_row] = NULL;
}

void	read_input(t_fdf	*fdf, char *path)
{
	fdf->points = (t_points ***)malloc(sizeof(t_points **) \
					* (fdf->height + 1));
	if (!fdf->points)
		print_error(MLC_ERROR);
	save_lines(fdf, path);
	ft_printf("\033[1;32mSUCCES:\033[1;0m Finished reading file.\n");
}

int	get_height(char *path)
{
	int		fd;
	char	*row;
	int		height;

	height = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error(OPN_ERROR);
	while (1)
	{
		row = ft_get_next_line(fd);
		if (!row)
			break ;
		height++;
		free(row);
	}
	close(fd);
	return (height);
}
