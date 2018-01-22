#include "../inc/p-lost.h"

void ft_moveUp(t_env *env)
{
	
	if (env->posY > 0 && env->floor.map[env->posY - 1][env->posX])
	{
		env->posY -= 1;
		env->floor.explored[env->posY][env->posX] = 1;
	}
}

void ft_moveDown(t_env *env)
{
	
	if (env->posY < 31 && env->floor.map[env->posY + 1][env->posX])
	{
		env->posY += 1;
		env->floor.explored[env->posY][env->posX] = 1;
	}
}

void ft_moveRight(t_env *env)
{
	
	if (env->posX < 31 && env->floor.map[env->posY][env->posX + 1])
	{
		env->posX += 1;
		env->floor.explored[env->posY][env->posX] = 1;
	}
}

void ft_moveLeft(t_env *env)
{
	
	if (env->posX > 0 && env->floor.map[env->posY][env->posX - 1])
	{
		env->posX -= 1;
		env->floor.explored[env->posY][env->posX] = 1;
	}
}
