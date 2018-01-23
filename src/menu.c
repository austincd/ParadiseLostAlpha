#include "../inc/p-lost.h"

void	menu(t_env *env, t_frame *frame, t_menu menu)
{
	int	counter;

	counter = 0;
	if (env && frame)
	{
		while (counter < 10)
		{
			if (menu.lines[counter])
				fontRender(env, frame, &(env->font), menu.lines[counter], 20, 20 * (counter + 1));
			++counter;
		}
		counter = 0;
		while (counter < 2)
		{
			if (menu.options[counter].text[0])
				fontRender(env, frame, &(env->font), menu.options[counter].text, 50, 300 + (20 * (counter + 1)));
			++counter;
		}
		env->inMenu = 1;
	}
}
