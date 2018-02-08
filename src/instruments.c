#include "../inc/p-lost.h"

static void	valEffect_apply(int *val, t_op *change)
{
	if (change && val)
	{
		if (change->operation == 0)
			*val += change->operand;
		else if (change->operation == 1)
			*val -= change->operand;
		else if (change->operation == 2)
			*val *= change->operand;
		else if (change->operation == 3)
			*val /= change->operand;
	}
}

void	statEffect_apply(t_combatant *applyTo, t_statEffect *effect)
{
	if (applyTo && effect)
	{
		valEffect_apply(applyTo->hp, &(effect->hp));
		valEffect_apply(applyTo->sp, &(effect->sp));
		valEffect_apply(applyTo->mass, &(effect->mass));
		valEffect_apply(applyTo->invitation, &(effect->invitation));
		valEffect_apply(applyTo->expertise, &(effect->expertise));
	}
}
