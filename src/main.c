#include "../inc/p-lost.h"

void	prepare(t_env *env)
{
	int counter;

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
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[0].framePtr, 0, 0);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[1].framePtr, env->resX / 2, 0);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[2].framePtr, 0, env->resY / 2);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[3].framePtr, env->resX / 2, env->resY / 2);
	}
}

int main()
{
	t_env env;

	ft_bzero(&env, sizeof(env));
	prepare(&env);

	while(1)
	{
		drawGrid(&env, env.views);
		drawGrid(&env, env.views + 2);
		drawGrid(&env, env.views + 1);
		drawGrid(&env, env.views + 3);
		drawViews(&env);
//		ft_framebuffer_forget(&env);
	}
}
