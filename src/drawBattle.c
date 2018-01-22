#include "../inc/p-lost.h"

void	drawBattleUnderlay(t_env *env, t_frame *frame)
{
	if (env && frame)
	{
		drawHorizontal(env, frame, frame->resX / 8, (frame->resX - frame->resX / 8), (frame->resY - ((frame->resY / 12))));
		drawHorizontal(env, frame, frame->resX / 8, (frame->resX - frame->resX / 8), (frame->resY - ((frame->resY / 12) + (frame->resY / 6))));
		drawHorizontal(env, frame, frame->resX / 8, (frame->resX - frame->resX / 8), (frame->resY / 12));
		drawHorizontal(env, frame, frame->resX / 8, (frame->resX - frame->resX / 8), (frame->resY / 12) + (frame->resY / 6));
		drawVertical(env, frame, frame->resY / 12, (frame->resY / 12) + (frame->resY / 6), frame->resX / 8);
		drawVertical(env, frame, frame->resY / 12, (frame->resY / 12) + (frame->resY / 6), (frame->resX - frame->resX / 8));
		drawVertical(env, frame, frame->resY - (frame->resY / 12 + frame->resY / 6), frame->resY - ((frame->resY / 12)), frame->resX / 8);
		drawVertical(env, frame, frame->resY - (frame->resY / 12 + frame->resY / 6), frame->resY - ((frame->resY / 12)), (frame->resX - frame->resX / 8));
		drawVertical(env, frame, frame->resY / 12, (frame->resY / 12) + (frame->resY / 6), frame->resX / 8 + (frame->resX / 16) * 3);
		drawVertical(env, frame, frame->resY / 12, (frame->resY / 12) + (frame->resY / 6), frame->resX / 8 + (frame->resX / 16) * 6);
		drawVertical(env, frame, frame->resY / 12, (frame->resY / 12) + (frame->resY / 6), frame->resX / 8 + (frame->resX / 16) * 9);
		drawVertical(env, frame, frame->resY - (frame->resY / 12 + frame->resY / 6), frame->resY - ((frame->resY / 12)), frame->resX / 8 + (frame->resX / 16) * 3);
		drawVertical(env, frame, frame->resY - (frame->resY / 12 + frame->resY / 6), frame->resY - ((frame->resY / 12)), frame->resX / 8 + (frame->resX / 16) * 6);
		drawVertical(env, frame, frame->resY - (frame->resY / 12 + frame->resY / 6), frame->resY - ((frame->resY / 12)), frame->resX / 8 + (frame->resX / 16) * 9);
		coloredRectangles(env, frame);
	}
}

void	coloredRectangles(t_env *env, t_frame *frame)
{
	t_pt alpha;
	t_pt beta;
	int counter;

	counter = 0;
	if (env && frame)
	{
		while (counter < 4)
		{
			alpha.x = 64 + (96 * counter);
			beta.x = alpha.x + 96;
			if (env->enemyParty[counter].active)
			{
				alpha.y = 138;
				beta.y = 256;
				fillRect(env, frame, alpha, beta, (env->enemyParty[counter].color));
			}
			if (env->alliedParty[counter].active)
			{
				alpha.y = 257;
				beta.y = 385;
				fillRect(env, frame, alpha, beta, (env->alliedParty[counter].color));
			}
			++counter;
		}
	}
}

void fillRect(t_env *env, t_frame *frame, t_pt alpha, t_pt beta, t_pix color)
{
	int xindex;
	int yindex;

	xindex = alpha.x;
	yindex = alpha.y;
	while (yindex < beta.y)
	{
		while (xindex < beta.x)
		{
			ft_mlx_ppp(env, frame, xindex, yindex, color);
			++xindex;
		}
		xindex = alpha.x;
		++yindex;
	}
}
