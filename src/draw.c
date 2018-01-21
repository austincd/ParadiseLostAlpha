#include "../inc/p-lost.h"
void drawHorizontal(t_env *env, t_frame *frame, int x1, int x2, int y)
{
	int x;
	t_pix color;

	x = x1;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.alpha = 0;
	if (env && frame)
	{
		while (x < x2)
		{
			ft_mlx_ppp(env, frame, x, y, color);
			++x;
		}
	}
}

void drawVertical(t_env *env, t_frame *frame, int y1, int y2, int x)
{
	int y;
	t_pix color;

	y = y1;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.alpha = 0;
	if (env && frame)
	{
		while (y < y2)
		{
			ft_mlx_ppp(env, frame, x, y, color);
			++y;
		}
	}
}

void	drawGrid(t_env *env, t_frame *frame)
{
	int	origin;
	int counter;

	counter = 0;
	origin = env->gridSize / 2;
	while (counter < 33)
	{
		drawHorizontal(env, frame, origin, (origin + env->gridSize * 32), (origin + env->gridSize * counter));
		drawVertical(env, frame, origin, (origin + env->gridSize * 32), (origin + env->gridSize * counter));
		++counter;
	}
}
