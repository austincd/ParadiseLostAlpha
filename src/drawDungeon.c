#include "../inc/p-lost.h"

void	fillGridSquare(t_env *env, t_frame *frame, int x, int y, t_pix color)
{
	t_pt	origin;
	t_pt	end;
	if (env && frame)
	{
		origin.x = env->gridSize / 2 + 1;
		origin.y = env->gridSize / 2 + 1;
		origin.x += (env->gridSize * x);
		origin.y += (env->gridSize * y);
		end.x = origin.x + env->gridSize;
		end.y = origin.y + env->gridSize;
		fillRect(env, frame, origin, end, color);
	}
}

void	drawSelf(t_env *env, t_frame *frame)
{
	t_pix	color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	if (env && frame)
	{
		drawFloor(env, frame);
		fillGridSquare(env, frame, env->posX, env->posY, color);
	}
}

void	drawFloor(t_env *env, t_frame *frame)
{
	int		y;
	int		x;
	t_pix	fog;

	x = 0;
	y = 0;
	fog.r = 150;
	fog.g = 50;
	fog.b = 80;
	while (y < 32)
	{
		while (x < 32)
		{
			if (env->floor.map[y][x])
			{
				if (env->floor.explored[y][x])
					fillGridSquare(env, frame, x, y, env->floor.palette[(int)(env->floor.map[y][x])]);
				else
					fillGridSquare(env, frame, x, y, fog);
			}
			++x;
		}
		x = 0;
		++y;
	}
}
