#include "../inc/p-lost.h"


void		playerAction(t_env *env, int action)
{
	t_combatant *target;
	t_combatant *self;

	self = env->alliedParty + env->activeAlly;
	if (env->targetFriendly)
		target = env->alliedParty + env->target;
	else
		target = env->enemyParty + env->target;
	if (action == 0)
		player_rightNormal(self, target);
	updateCombatant(target);
	updateCombatant(self);
	battleCheck(env);
}
//static void		ft_enemyTurn(t_plost *env);

void	battle()
{
		ft_playerTurn(env);
		ft_enemyTurn(env);
}

static void		player_rightNormal(t_combatant *user, t_combatant *target)
{
	if (user && target)
	{
		statEffect_apply(user, &user->left.special.cost);
		statEffect_apply(target, &user->left.special.effect);
	}
}

static void		player_rightSpecial(t_combatant *user, t_combatant *target)
{
	if (user && target && user->sp > 0)
	{
		statEffect_apply(user, &user->right.special.cost);
		statEffect_apply(target, &user->right.special.effect);
	}
}

static void		player_leftNormal(t_combatant *user, t_combatant *target)
{
	if (user && target)
	{
		statEffect_apply(user, &user->left.special.cost);
		statEffect_apply(target, &user->left.special.effect);
	}
}

static void		player_leftSpecial(t_combatant *user, t_combatant *target)
{
	if (user && target && user->sp > 0)
	{
		statEffect_apply(user, &user->left.special.cost);
		statEffect_apply(target, &user->left.special.effect);
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
