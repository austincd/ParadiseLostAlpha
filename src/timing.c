/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:16:19 by adaly             #+#    #+#             */
/*   Updated: 2017/11/10 01:05:16 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/p-lost.h"

void	ft_expire(t_env *env, long double *value)
{
	if (env && value)
	{
		if (*value <= ((double)env->tickLength / 1000))
			*value = 0;
		else
			*value -= ((double)env->tickLength / 1000);
	}
}

void	ft_decay(t_env *env)
{
	if (env)
	{
		ft_expire(env, &(env->chainTime));
		ft_expire(env, &(env->turnTime));
	}
}

void	ft_timing(t_env *env)
{
	long double	temp;

	temp = 1.0000;
	if (env)
	{
		temp /= env->tickRate;
		env->tickLength = (int)(temp * 1000);
	}
}
