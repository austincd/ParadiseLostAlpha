#include "../inc/p-lost.h"

void loadFont(t_env *env)
{
	if (env)
	{
		env->font.alpha[0] = loadImage(ft_open_file("assets/font/a"), 12, 12);
		env->font.alpha[1] = loadImage(ft_open_file("assets/font/b"), 12, 12);
		env->font.alpha[2] = loadImage(ft_open_file("assets/font/c"), 12, 12);
		env->font.alpha[3] = loadImage(ft_open_file("assets/font/d"), 12, 12);
		env->font.alpha[4] = loadImage(ft_open_file("assets/font/e"), 12, 12);
		env->font.alpha[5] = loadImage(ft_open_file("assets/font/f"), 12, 12);
		env->font.alpha[6] = loadImage(ft_open_file("assets/font/g"), 12, 12);
		env->font.alpha[7] = loadImage(ft_open_file("assets/font/h"), 12, 12);
		env->font.alpha[8] = loadImage(ft_open_file("assets/font/i"), 12, 12);
		env->font.alpha[9] = loadImage(ft_open_file("assets/font/j"), 12, 12);
		env->font.alpha[10] = loadImage(ft_open_file("assets/font/k"), 12, 12);
		env->font.alpha[11] = loadImage(ft_open_file("assets/font/l"), 12, 12);
		env->font.alpha[12] = loadImage(ft_open_file("assets/font/m"), 12, 12);
		env->font.alpha[13] = loadImage(ft_open_file("assets/font/n"), 12, 12);
		env->font.alpha[14] = loadImage(ft_open_file("assets/font/o"), 12, 12);
		env->font.alpha[15] = loadImage(ft_open_file("assets/font/p"), 12, 12);
		env->font.alpha[16] = loadImage(ft_open_file("assets/font/q"), 12, 12);
		env->font.alpha[17] = loadImage(ft_open_file("assets/font/r"), 12, 12);
		env->font.alpha[18] = loadImage(ft_open_file("assets/font/s"), 12, 12);
		env->font.alpha[19] = loadImage(ft_open_file("assets/font/t"), 12, 12);
		env->font.alpha[20] = loadImage(ft_open_file("assets/font/u"), 12, 12);
		env->font.alpha[21] = loadImage(ft_open_file("assets/font/v"), 12, 12);
		env->font.alpha[22] = loadImage(ft_open_file("assets/font/w"), 12, 12);
		env->font.alpha[23] = loadImage(ft_open_file("assets/font/x"), 12, 12);
		env->font.alpha[24] = loadImage(ft_open_file("assets/font/y"), 12, 12);
		env->font.alpha[25] = loadImage(ft_open_file("assets/font/z"), 12, 12);
		env->font.period = loadImage(ft_open_file("assets/font/period"), 12, 12);
		env->font.space = loadImage(ft_open_file("assets/font/space"), 12, 12);
		env->font.size = 12;
	}
}

static t_tex	selectChar(t_font *font, char c)
{
	if (font && c)
	{
		if (c >= 'A' && c <= 'Z')
			return (font->alpha[c - 'A']);
		else if (c == '.')
			return (font->period);
		else if (c == '-')
			return (font->hyphen);
	}
	return (font->space);
}

void fontRender(t_env *env, t_frame *frame, t_font *font, char *line, int x1, int y1)
{
	int x;
	int y;
	int counter;
	int length;
	t_tex charRender;

	y = y1;
	x = x1;
	counter = 0;
	if (env && frame && font && line)
	{
		length = ft_strlen(line);
		while (counter < length)
		{
			charRender = selectChar(font, line[counter]);
			x += font->size + 1;
//			printf("x = %d\nfont->size = %d\n", x, font->size);
			applyImage(env, frame, x, y, charRender);
//			printf("appliedimage!\n");
			++counter;
		}
	}
}
