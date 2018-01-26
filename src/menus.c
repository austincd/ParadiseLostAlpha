#include "../inc/p-lost.h"

void	startGame(t_env *env)
{
	if (env)
		env->inMenu = 0;
}

t_menu	*startMenu(void)
{
	t_menu	*start;

	start = (t_menu*)ft_memalloc(sizeof(t_menu));
	start->lines[0] = ft_strdup("PARADISE LOST ALPHA");
//	start.lines[2] = ft_strdup("INTERACTIVE PROOF OF CONCEPT");
//	start.lines[7] = ft_strdup("WE HOPE YOU HAVE FUN TODAY");
//	start.lines[9] = ft_strdup("M-M.INSTITUTE");
	start->numLines = 10;
	start->numOptions = 2;
	ft_strcpy(start->options[0].text, "PRESS ONE");// TO PUT THE FEAR OF GOD IN A MAN");
	ft_strcpy(start->options[1].text, "PRESS TWO");// TO GO BACK HOME");
	start->options[0].effect = &startGame;
	start->options[1].effect = &callExit;
	return (start);
}
