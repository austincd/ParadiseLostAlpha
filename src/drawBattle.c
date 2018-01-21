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
	}
}
