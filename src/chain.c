#include "../inc/p-lost.h"

void	startChain(t_env *env)
{
	if (!env->chainTime)
	{
		env->chainTime = 2.0;
	}
}
