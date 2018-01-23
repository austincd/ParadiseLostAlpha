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
		if (env->inBattle)
			applyImage(env, frame, 96, 96, env->textures[4]);
		if (env->inBattle)
			coloredRectangles(env, frame);
//		printf("turnTime left:%Lf\n", env->turnTime);
		if (env->target == 0)
			applyImage(env, frame, 96, 208 + (env->targetFriendly * 64), env->textures[1]);
		else if (env->target == 1)
			applyImage(env, frame, 192, 208 + (env->targetFriendly * 64), env->textures[0]);
		else if (env->target == 2)
			applyImage(env, frame, 282, 208 + (env->targetFriendly * 64), env->textures[2]);
		else if (env->target == 3)
			applyImage(env, frame, 384, 208 + (env->targetFriendly * 64), env->textures[3]);
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
			if (env->enemyParty[counter].active && env->whoseTurn)
			{
				alpha.y = 128;
				beta.y = 258;
				fillRect(env, frame, alpha, beta, (env->enemyParty[counter].color));
			}
			if (env->alliedParty[counter].active && !env->whoseTurn)
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
