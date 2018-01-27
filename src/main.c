#include "../inc/p-lost.h"

void	prepare(t_env *env)
{
	int counter;

	ft_strcat(env->tileFile.path, "floor1");
	env->tileFile.fd = ft_open_file(env->tileFile.path);
	counter = 0;
	env->gridSize = 15;
	env->tickRate = 60;
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
	counter = 0;
	while (counter < 36)
	{
		env->log[counter] = ft_strnew(36);
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
//		fontRender(env, env->views + 2, &(env->font), ft_strdup("HELLO LOVE"), 40, 200);
		drawLog(env);
		fontRender(env, env->views, &env->font, "DUNGEON VIEW", 12, 494);
		fontRender(env, env->views + 1, &env->font, "BATTLE VIEW", 12, 494);
		fontRender(env, env->views + 2, &env->font, "MENU VIEW", 12, 494);
		fontRender(env, env->views + 3, &env->font, "LOG VIEW", 12, 494);
		if (!env->inBattle && !env->inMenu)
			mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[0].framePtr, 0, 0);
		else if (!env->inMenu)
			mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->views[1].framePtr, env->resX / 2, 0);
		else if (env->inMenu)
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
	t_file texture;

	ft_bzero(&texture, sizeof(t_file));
	ft_strcat(texture.path, "assets/images/arrowUp");
	texture.fd = ft_open_file(texture.path);
	ft_bzero(&env, sizeof(env));
	env.textures[0] = loadImage(texture.fd, 32, 32);
	ft_strcpy(texture.path, "assets/images/arrowDown");
	texture.fd = ft_open_file(texture.path);
	env.textures[1] = rotateImage(env.textures[0]);
	env.textures[2] = loadImage(texture.fd, 32, 32);
	env.textures[3] = rotateImage(env.textures[2]);
	ft_strcpy(texture.path, "assets/images/form");
	texture.fd = ft_open_file(texture.path);
	env.textures[4] = loadImage(texture.fd, 32, 32);
	env.textures[5] = loadImage(ft_open_file("assets/images/party"), 16, 16);
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
	env.floor.chainColor = color1;
	env.alliedParty[0].color = color4;
	env.alliedParty[1].color = color2;
	env.alliedParty[2].color = color3;
	env.alliedParty[3].color = color1;
	env.alliedParty[0].active = 1;
	env.alliedParty[1].active = 1;
	env.alliedParty[2].active = 1;
	env.alliedParty[3].active = 1;
	color1.b = 100;
	color1.g = 150;
	color1.r = 100;
	color2.b = 120;
	color2.r = 180;
	color2.g = 100;
	color3.b = 0;
	color3.r = 30;
	color3.g = 70;
	color4.b = 30;
	color4.g = 5;
	color4.r = 5;
	env.enemyParty[0].color = color4;
	env.enemyParty[1].color = color2;
	env.enemyParty[2].color = color3;
	env.enemyParty[3].color = color1;
	env.enemyParty[0].active = 1;
	env.enemyParty[1].active = 1;
	env.enemyParty[2].active = 1;
	env.enemyParty[3].active = 1;
	color1.r = 255;
	color1.g = 255;
	color1.b = 255;
	env.texPalette[0] = color1;
	env.texPalette[1] = color1;
	loadFont(&env);
	env.menuPtr = (void*)startMenu();
	env.inMenu = 1;
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
