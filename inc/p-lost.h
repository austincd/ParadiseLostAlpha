#ifndef PLOST_H
# define PLOST H
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_keys_macos.h"
# define WHITE 0xFFFFFF


typedef struct	s_pix{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	alpha;
}				t_pix;

typedef struct	s_floor
{
	char	name[32];
	char	description[32];
	char		**map;
	char		**explored;
	t_pix	palette[64];
	t_pix	chainColor;
}				t_floor;
/*
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


typedef struct	s_pt
{
	int x;
	int y;
}				t_pt;

typedef struct  s_tex{
	int     resX;
	int     resY;
	char	**data;
}				t_tex;

typedef struct  s_font{
	t_tex alpha[26];
	t_tex digits[10];
	t_tex space;
	t_tex period;
	t_tex hyphen;
	int size;
}				t_font;

typedef struct  s_frame{
	int     resX;
	int     resY;
	void	*framePtr;
	void	*frameData;
}				t_frame;

typedef struct		s_combatant
{
	char			active;
	char		name[32];
	int 			HP;
	int 			SP;
	t_pix			color;
//	t_instrument	*left;
//	t_instrument	*right;
}					t_combatant;

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
	char		toggleMode;
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
	char		one;
	char        two;
}				t_kb;

/*typedef struct	s_party
{
	t_combatant	lineUp[4];
	}				t_party;*/
typedef struct	s_file
{
	char	path[64];
	int		fd;
}				t_file;

typedef struct	s_env
{
	int posX;
	int posY;
	t_frame	views[4];
	t_file		tileFile;
	int			gridSize;
	int 		resX;
	int 		resY;
	t_mlx		mlx;
	t_floor 	floor;
	int			target;
	int			inBattle;
	int			inMenu;
	t_font		font;
	void   *menuPtr;
	int			targetFriendly;
	long double		chainTime;
	long double		turnTime;
	t_combatant		alliedParty[4];
	t_combatant		enemyParty[4];
	int tickLength;
	t_kb	keys;
	int tickRate;
	t_tex		textures[32];
	t_pix		texPalette[32];
	char		whoseTurn;
}				t_env;

typedef struct	s_option
{
	char		text[32];
	void		(*effect)(t_env*);
}				t_option;

typedef struct	s_menu
{
	char		*lines[10];
	t_option	options[6];
	int			numOptions;
	int			numLines;
}				t_menu;

void fontRender(t_env *env, t_frame *frame, t_font *font, char *line, int x1, int y1);
void loadFont(t_env *env);
void	menu(t_env *env, t_frame *frame, t_menu *menu);
t_menu	*startMenu(void);
void    startGame(t_env *env);
void                    ft_menuControl(t_env *env);



void	startChain(t_env *env);
void	drawBorder(t_env *env, t_frame *frame);
void	drawViews(t_env *env);
int		key_release_hook(int keycode, t_env *env);
int		key_press_hook(int keycode, t_env *env);
int     ft_loop(t_env *env);
void    ft_battleControl(t_env *env);
void            ft_dungeonControl(t_env *env);
void callExit(t_env *env);
int     exit_hook(t_env *env);
void        ft_hooks(t_env *env);
void	ft_startChain(t_env *env);
void	drawFloor(t_env *env, t_frame *frame);
void	ft_framebuffer_forget(t_env *env, t_frame *frame);
void	ft_mlx_ppp(t_env *env, t_frame *frame, int x, int y, t_pix color);
void	drawGrid(t_env *env, t_frame *frame);
void	drawSelf(t_env *env, t_frame *frame);
void	drawBattleUnderlay(t_env *env, t_frame *frame);
void	drawVertical(t_env *env, t_frame *frame, int y1, int y2, int x);
void	drawHorizontal(t_env *env, t_frame *frame, int x1, int x2, int y);
void    fillRect(t_env *env, t_frame *frame, t_pt alpha, t_pt beta, t_pix color);
void	coloredRectangles(t_env *env, t_frame *frame);
void	ft_timing(t_env *env);
void	ft_decay(t_env *env);
void	ft_expire(t_env *env, long double *value);
void	ft_moveUp(t_env *env);
void	ft_moveDown(t_env *env);
void	ft_moveLeft(t_env *env);
void	ft_moveRight(t_env *env);
void	loadFloor(t_env *env);
void	readFloor(t_env *env);
t_tex	loadImage(int fd, int resX, int resY);
t_tex	rotateImage(t_tex image);
void	applyImage(t_env *env, t_frame *frame, int x1, int y1, t_tex img);

#endif
