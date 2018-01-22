#include "../inc/p-lost.h"

void readFloor(t_env *env)
{
	int		counter;
	int		index;
	char	*line;

	counter = 0;
	index = 0;
	line = NULL;
	while (env && counter < 32)
	{
		get_next_line(env->tileFile.fd, &line);
		while (index < 32)
		{
			env->floor.map[counter][index] = line[index] - '0';
			++index;
		}
		index = 0;
		++counter;
	}
}
