#include "../inc/p-lost.h"

t_tex	loadImage(int fd, int resX, int resY)
{
	char	*line;
	int		counter;
	t_tex	image;

	counter = 0;
	line = NULL;
	ft_bzero(&image, sizeof(t_tex));
	if (fd >= 0 && resX && resY)
	{
		image.resX = resX;
		image.resY = resY;
		image.data = (char**)ft_memalloc(sizeof(char*) * resY);
		while (get_next_line(fd, &line) && counter < resY)
		{
			image.data[counter] = line;
			line = NULL;
			++counter;
		}
	}
	return (image);
}

void		applyImage(t_env *env, t_frame *frame, int x1, int y1, t_tex img)
{
	int		x;
	int		y;
	t_pix	color;

	x = x1;
	y = y1;
	while (y < frame->resY && y < y1 + img.resY)
	{
		while (x < frame->resX && x < x1 + img.resX)
		{
			if (img.data[y - y1][x - x1] > '0')
			{
				color = env->texPalette[(int)(img.data[y - y1][x - x1] - '0')];
				ft_mlx_ppp(env, frame, x, y, color);
			}
			++x;
		}
		x = x1;
		++y;
	}
}
