#include "../inc/p-lost.h"

void	nextCombatant(t_party *party)
{
	if (party)
	{
		party->activeCombatant += 1;
		if (party->activeCombatant >= party->numCombatants)
			party->activeCombatant = 0;
	}
}

void	battleStatus(t_env *env)
{
	if (env && env->inBattle)
	{
		
	}
}

void	updateCombatant(t_combatant *target)
{
	if (target)
	{
	  target->mass.strength = target->mass.baseValue + ((target->mass.baseValue / 10) * target->mass.buffLevel);
	  target->expertise.strength = target->expertise.baseValue + ((target->expertise.baseValue / 10) * target->expertise.buffLevel);
	  target->invitation.strength = target->invitation.baseValue + ((target->invitation.baseValue / 10) * target->invitation.buffLevel);
		if (target->hp <= 0)
		{
			target->hp = 0;
			target->gone = 1;
		}
		if (target->sp <= 0)
		{
			target->sp = 0;
			target->depleted = 1;
		}
	}
}
