/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 04:58:56 by adaly             #+#    #+#             */
/*   Updated: 2017/11/24 15:03:03 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/p-lost.h"

void		ft_hooks(t_env *env)
{
	if (env)
	{
	mlx_do_key_autorepeatoff(env->mlx.mlx);
	mlx_hook(env->mlx.win, 2, 0, key_press_hook, env);
	mlx_hook(env->mlx.win, 3, 0, key_release_hook, env);
//	mlx_hook(env->mlx.win, 12, 0, expose_hook, env);
	mlx_hook(env->mlx.win, 17, 0, exit_hook, env);
	mlx_loop_hook(env->mlx.mlx, ft_loop, env);
	}
}

int		ft_loop(t_env *env)
{
	if (env->inBattle)
		ft_battleControl(env);
	else
		ft_dungeonControl(env);
	usleep(env->tickLength);
	ft_decay(env);
	return (0);
}

int		key_release_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_SHIFT_LEFT)
		;
	else if (keycode == KEY_W)
		env->keys.forward = 0;
	else if (keycode == KEY_A)
		env->keys.left = 0;
	else if (keycode == KEY_S)
		env->keys.backward = 0;
	else if (keycode == KEY_D)
		env->keys.right = 0;
	else if (keycode == KEY_LEFT)
	{
		if (env->keys.turnLeft < (env->tickRate / 2))
			env->keys.fadeLeft = 1;
		env->keys.turnLeft = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		if (env->keys.turnRight < (env->tickRate / 2))
			env->keys.fadeRight = 1;
		env->keys.turnRight = 0;
	}
	return (0);
}

int		key_press_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE)
		exit_hook(env);
	if (keycode == KEY_SPACEBAR)
		;//ft_attack(env);
	else if (keycode == KEY_W)
		env->keys.forward += 1;
	else if (keycode == KEY_A)
		env->keys.left += 1;
	else if (keycode == KEY_S)
		env->keys.backward += 1;
	else if (keycode == KEY_D)
		env->keys.right += 1;
	else if (keycode == KEY_LEFT)
		env->keys.turnLeft += 1;//ft_fade_left(env);
	else if (keycode == KEY_RIGHT)
		env->keys.turnRight += 1;//ft_fade_right(env);
	return (0);
}

void			ft_battleControl(t_env *env)
{
	if (env)
	{
		if (env->keys.targetFriendly)
			env->targetFriendly = 1;
		if (env->keys.targetUp)
			env->target = 0;
		else if (env->keys.targetDown)
			env->target = 1;
		else if (env->keys.targetLeft)
			env->target = 2;
		else if (env->keys.targetRight)
			env->target = 3;
		if (env->keys.leftNormal)
			player_leftNormal(env);
		else if (env->keys.leftSpecial)
			player_leftSpecial(env);
		else if (env->keys.rightNormal)
			player_rightNormal(env);
		else if (env->keys.rightSpecial)
			player_rightSpecial(env);
	}
}

void			ft_dungoenControl(t_env *env)
{
	if (env)
	{
		if (env->keys.forward)
			ft_moveUp(env);
		if (env->keys.backward)
			ft_moveDown(env);
		if (env->keys.fadeLeft == 1)
			ft_moveLeft(env);
		if (env->keys.fadeRight == 1)
			ft_moveRight(env);
		if (!env->chainTime && env->keys.startChain)
			ft_startChain(env);
	}
}

int		exit_hook(t_env *env)
{
	int i;

	i = -1;
	if (env)
	{
		if (env->mlx.mlx && env->mlx.win)
			mlx_destroy_window(env->mlx.mlx, env->mlx.win);
		mlx_destroy_image(env->mlx.mlx, env->mlx.frame.framePtr);
		ft_bzero(env, sizeof(t_env));
	}
	exit(0);
}
