#include "../inc/p-lost.h"

typedef struct	s_stat
{
  int		baseValue;
  int		buffLevel;
  int		strength;
}		t_stat;


t_stat mass;
t_stat expertise;
t_stat invitation;
char	implosion;
char	mania;
char	dissociation;


void	forcefulAttack(t_combatant *user, t_combatant *target)
{
  int force;

  if (user && target)
    {
      force = (user->mass.strength * target->mass.strength);
      if (user->implosion)
      {
	target->HP -= (force * force);
	user->implosion = 0;
      }
      else
	target->HP -= force;
    }
}

void	technicalAttack(t_combatant *user, t_combatant *target)
{
  int technique;

  if (user && target)
    {
      technique = (user->expertise.strength * target->expertise.strength);
      if (user->mania)
      {
	target->HP -= (technique * technique);
	user->mania = 0;
      }
      else
	target->HP -= technique;
    }
}

void	occultAttack(t_combatant *user, t_combatant *target)
{
  int pull;

  if (user && target)
    {
      pull = (user->invitation.strength * target->invitation.strength);
      if (user->dissociation)
      {
	target->HP -= (pull * pull);
	user->dissociation = 0;
      }
      else
	target->HP -= pull;
    }
}

void	forcefulHeal(t_combatant *user, t_combatant *target)
{
  int force;

  if (user && target)
    {
      force = (user->mass.strength * target->mass.strength);
      if (user->implosion)
      {
	target->HP += (force * force);
	user->implosion = 0;
      }
      else
	target->HP += force;
    }
}

void	technicalHeal(t_combatant *user, t_combatant *target)
{
  int technique;

  if (user && target)
    {
      technique = (user->expertise.strength * target->expertise.strength);
      if (user->mania)
      {
	target->HP += (technique * technique);
	user->mania = 0;
      }
      else
	target->HP += technique;
    }
}

void	occultHeal(t_combatant *user, t_combatant *target)
{
  int pull;

  if (user && target)
    {
      pull = (user->invitation.strength * target->invitation.strength);
      if (user->dissociation)
      {
	target->HP += (pull * pull);
	user->dissociation = 0;
      }
      else
	target->HP += pull;
    }
}

void	buffMass(t_combatant *user, t_combatant *target);
{
  if (user && target && user->SP > 0)
  {
    user->SP -= 10;
    target->mass.buffLevel += 1;
  }
}

void	buffExpertise(t_combatant *user, t_combatant *target);
{
  if (user && target && user->SP > 0)
  {
    user->SP -= 10;
    target->mass.buffLevel += 1;
  }
}

void	buffInvitation(t_combatant *user, t_combatant *target);
{
  if (user && target && user->SP > 0)
  {
    user->SP -= 10;
    target->mass.buffLevel += 1;
  }
}

void	debuffMass(t_combatant *user, t_combatant *target);
{
  if (user && target && user->SP > 0)
  {
    user->SP -= 10;
    target->mass.buffLevel -= 1;
  }
}

void	debuffExpertise(t_combatant *user, t_combatant *target);
{
  if (user && target && user->SP > 0)
  {
    user->SP -= 10;
    target->expertise.buffLevel -= 1;
  }
}

void	debuffInvitation(t_combatant *user, t_combatant *target);
{
  if (user && target && user->SP > 0)
  {
    user->SP -= 10;
    target->invitation.buffLevel -= 1;
  }
}
