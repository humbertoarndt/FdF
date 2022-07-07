#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int y, int x, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if	(mlx == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Janela");
	if	(mlx_win == NULL)
	{
		free (mlx_win);
		return (MLX_ERROR);
	}
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//Drawn Left side
	my_mlx_pixel_put(&img, 5, 5, 0x00CCFF33);
	my_mlx_pixel_put(&img, 6, 5, 0x00CCFF33);
	my_mlx_pixel_put(&img, 7, 5, 0x00CCFF33);
	my_mlx_pixel_put(&img, 8, 5, 0x00CCFF33);
	my_mlx_pixel_put(&img, 9, 5, 0x00CCFF33);
	my_mlx_pixel_put(&img, 10, 5, 0x00CCFF33);

	//Drawn Up side
	my_mlx_pixel_put(&img, 5, 6, 0x00FFFF00);
	my_mlx_pixel_put(&img, 5, 7, 0x00FFFF00);
	my_mlx_pixel_put(&img, 5, 8, 0x00FFFF00);
	my_mlx_pixel_put(&img, 5, 9, 0x00FFFF00);
	my_mlx_pixel_put(&img, 5, 10, 0x00FFFF00);

	//Drawn right side
	my_mlx_pixel_put(&img, 5, 10, 0x00CCFFFF);
	my_mlx_pixel_put(&img, 6, 10, 0x00CCFFFF);
	my_mlx_pixel_put(&img, 7, 10, 0x00CCFFFF);
	my_mlx_pixel_put(&img, 8, 10, 0x00CCFFFF);
	my_mlx_pixel_put(&img, 9, 10, 0x00CCFFFF);
	my_mlx_pixel_put(&img, 10, 10, 0x00CCFFFF);

	//Drawn Dwon side
	my_mlx_pixel_put(&img, 10, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 10, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 10, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 10, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}