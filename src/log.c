#include "../inc/p-lost.h"

//LOG: 1024 X 1024 QUADRANT OF THE GAME WINDOW INTENDED TO DISPLAY TEXT MESSAGES 36 x 36

void	consoleLog(t_env *env, char *str)
{
	int numLines;
	int counter;

	counter = 0;
	if (env && str)
	{
		numLines = ft_strlen(str) / 36;
		if (ft_strlen(str) % 36)
			numLines += 1;
		counter = 35;
		while (counter >= numLines)
		{
			if (35 - counter < numLines)
				ft_strdel_plus(env->log + counter);
			ft_strlcpy(env->log[counter], env->log[counter - numLines], 36);
			--counter;
		}
		counter = 0;
		while (counter < numLines)
		{
			ft_strlcpy(env->log[counter], str + (35 * counter), 36);
			++counter;
		}
	}
}

void drawLog(t_env *env)
{
	int counter;

	counter = 0;
	if (env)
	{
		while (counter < 36)
		{
			fontRender(env, env->views + 3, &env->font, env->log[counter], 10, 10 + (counter * 16));
			++counter;
		}
	}
}
