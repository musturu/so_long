
#include "../so_long.h"

t_image	new_file_img(char * path, void *mlx_ptr)
{
	t_image image;

	image.img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &image.w, &image.h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
		&(image.line_len), &(image.endian));
	return (image);
}

void	put_pixel_img(t_image img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h) {
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_image img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}

void	put_img_to_img(t_image dst, t_image src, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

t_image	new_img(int w, int h, void *mlx)
{
	t_image	image;

	image.img_ptr = mlx_new_image(mlx, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}