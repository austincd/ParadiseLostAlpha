#ifndef PLOST_H
# define PLOST H
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_keys_macos.h"
# define WHITE 0xFFFFFF

/*
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
*/

typedef struct	s_pix{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	alpha;
}				t_pix;

typedef struct  s_frame{
	int     resX;
	int     resY;
	void	*framePtr;
	void	*frameData;
}				t_frame;

typedef struct  s_mlx{
	void		*mlx;
	void		*win;
	int			bppx;
	int			endi;
	int			bpln;
    t_frame     frame;                                                                    
}               t_mlx;

typedef struct	s_kb
{
	char		exit;
	char		up;
	char		down;
	char		left;
	char		right;
	char		targetFriendly;
	char		startChain;
	char		leftNormal;
	char		leftSpecial;
	char		rightNormal;
	char		rightSpecial;
}				t_kb;

typedef struct	s_env
{
	t_frame	views[4];
	int			gridSize;
	int 		resX;
	int 		resY;
	t_mlx		mlx;
	int			inBattle;
	int			targetFriendly;
	double		chainTime;
	double		turnTime;
}				t_env;

void	ft_framebuffer_forget(t_env *env);
void	ft_mlx_ppp(t_env *env, t_frame *frame, int x, int y, t_pix color);
void	drawGrid(t_env *env, t_frame *frame);
void	drawBattleUnderlay(t_env *env, t_frame *frame);
void	drawVertical(t_env *env, t_frame *frame, int y1, int y2, int x);
void	drawHorizontal(t_env *env, t_frame *frame, int x1, int x2, int y);

#endif
