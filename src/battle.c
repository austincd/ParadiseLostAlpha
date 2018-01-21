#include "../inc/p-lost.h"


static void		ft_playerTurn(t_plost *env)
{
	double	timeLeft;

	env->timeLeft = 4.0;
	while (env->timeLeft >= 0.1)
	{
		
	}
}
static void		ft_enemyTurn(t_plost *env);

void	battle()
{
	while (!complete)
	{
		ft_playerTurn(env);
		ft_enemyTurn(env);
	}
}

static void		ft_rightNormal(t_combatant *user, t_combatant *target)
{
	if (user && target)
	{
		target->hp += user->right.normalEffects.hp;
		target->sp += user->right.normalEffects.sp;
	}
}

static void		ft_rightSpecial(t_combatant *user, t_combatant *target)
{
	if (user && target && user->sp >= user->right.spCost)
	{
		user->sp -= user->right.spCost;
		target->hp += user->right.specialEffects.hp;
		target->sp += user->right.specialEffects.sp;
	}
}

static void		ft_leftNormal(t_combatant *user, t_combatant *target)
{
	if (user && target)
	{
		target->hp += user->left.normalEffects.hp;
		target->sp += user->left.normalEffects.sp;
	}
}

static void		ft_leftSpecial(t_combatant *user, t_combatant *target)
{
	if (user && target && user->sp >= user->right.spCost)
	{
		user->sp -= user->left.spCost;
		target->hp += user->left.specialEffects.hp;
		target->sp += user->left.specialEffects.sp;
	}
}

static void		ft_swapDeck(t_combatant *user)
{
	if (user)
	{
		if (user->currentDeck)
			user->currentDeck = 0;
		else
			user->currentDeck = 1;
		user->right = decks[currentDeck].right;
		user->left = decks[currentDeck].left;
	}
}
