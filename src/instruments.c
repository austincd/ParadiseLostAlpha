#include "../inc/p-lost.h"

void	statEffect_apply(t_combatant *applyTo, t_statEffect *effect)
{
	if (applyTo && effect)
	{
		applyTo->hp += effect->hp;
		applyTo->sp += effect->sp;
	}
}
