#include "../libft/libft.h"

typedef struct		s_combatant
{
	char			active;
	char[32]		name;
	int 			HP;
	int 			SP;
	t_instrument	*left;
	t_instrument	*right;
}					t_combatant;

typedef struct	s_floor
{
	char[32]	name;
	char[32]	description;
	char		**map;
	char		**explored;
}				t_floor;

typedef struct	s_enemy
{
}				t_enemy;

typedef struct	s_encounter
{
	int 		numEnemies;
	char[256]	flavorText;
	t_combatant	down;
	t_combatant	up;
	t_combatant	left;
	t_combatant	right;
	t_combatant	downRight;
	t_combatant	downLeft;
	t_combatant	upRight;
	t_combatant	upLeft;
}				t_encounter;

typedef struct	s_party
{
}

typedef struct	s_plost
{
	int			resX;
	int			resY;
}				t_plost;
