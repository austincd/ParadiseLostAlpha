void	menu(t_env *env, t_frame *frame, t_menu menu)
{
	int	counter;

	counter = 0;
	if (env && frame)
	{
		while (counter < menu.numLines)
		{
			mlx_string_put(env->mlx.mlx, env->mlx.win, 536, WHITE, menu.lines[counter]);
		}
	}
}
