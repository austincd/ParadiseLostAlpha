#include "../inc/p-lost.h"

void	prepare(t_env *env)
{
	int counter;

	ft_strcat(env->tileFile.path, "floor1");
	env->tileFile.fd = ft_open_file(env->tileFile.path);
	counter = 0;
	env->gridSize = 15;
	env->resX = 1024;
	env->resY = 1024;
	env->mlx.mlx = mlx_init();
	env->mlx.win = mlx_new_window(env->mlx.mlx, env->resX, env->resY, "PARADISE LOST! Alpha");
//	env->mlx.frame.framePtr = mlx_new_image(env->mlx.mlx, env->resX, env->resY);
//	env->mlx.frame.frameData = (unsigned int *)mlx_get_data_addr(env->mlx.frame.framePtr, &(env->mlx.bppx), &(env->mlx.bpln), &(env->mlx.endi));
	while (counter < 4)
	{
		env->views[counter].resX = env->resX / 2;
		env->views[counter].resY = env->resY / 2;
		env->views[counter].framePtr = mlx_new_image(env->mlx.mlx, env->views[counter].resX, env->views[counter].resY);
		env->views[counter].frameData = (unsigned int *)mlx_get_data_addr(env->views[counter].framePtr, &(env->mlx.bppx), &(env->mlx.bpln), &(env->mlx.endi));
		++counter;
	}
}

void	drawViews(t_env *env)
{
	if (env)
	{
		drawBorder(env, env->views);
		drawBorder(env, env->views + 1);
		drawBorder(env, env->views + 2);
		drawBorder(env, env->views + 3);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[0].framePtr, 0, 0);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[1].framePtr, env->resX / 2, 0);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[2].framePtr, 0, env->resY / 2);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[3].framePtr, env->resX / 2, env->resY / 2);
	}
	ft_framebuffer_forget(env, env->views);
	ft_framebuffer_forget(env, env->views + 1);
	ft_framebuffer_forget(env, env->views + 2);
	ft_framebuffer_forget(env, env->views + 3);
}

int main()
{
	t_env env;
	t_pix color1;
	t_pix color2;
	t_pix color3;
	t_pix color4;

	ft_bzero(&env, sizeof(env));
	color1.r = 100;
	color1.g = 150;
	color1.b = 100;
	color2.r = 120;
	color2.b = 180;
	color2.g = 100;
	color3.b = 0;
	color3.r = 30;
	color3.g = 70;
	color4.r = 30;
	color4.g = 5;
	color4.b = 5;
	prepare(&env);
	loadFloor(&env);
	ft_hooks(&env);
	env.floor.palette[1] = color2;
	env.alliedParty[0].color = color4;
	env.alliedParty[1].color = color2;
	env.alliedParty[2].color = color3;
	env.alliedParty[3].color = color1;
	env.alliedParty[0].active = 1;
	env.alliedParty[1].active = 1;
	env.alliedParty[2].active = 1;
	env.alliedParty[3].active = 1;
	mlx_loop(env.mlx.mlx);
}

void loadFloor(t_env *env)
{
	int		counter;

	counter = 0;
	if (env)
	{
		env->floor.map = (char**)ft_memalloc(sizeof(char*) * 33);
		env->floor.explored = (char**)ft_memalloc(sizeof(char*) * 33);
		while (counter < 32)
		{
			env->floor.explored[counter] = (char*)ft_memalloc(sizeof(char) * 33);
			env->floor.map[counter] = (char*)ft_memalloc(sizeof(char) * 33);
			++counter;
		}
		readFloor(env);
	}
}
