/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:14:27 by ylisyak           #+#    #+#             */
/*   Updated: 2018/10/12 22:50:08 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_timer.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"
# include <stdbool.h>
# include <dirent.h>
# include <stdio.h>
# include <libft.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

# define SCREEN_WIDTH 1800
# define SCREEN_HEIGHT 999
# define SCREEN_HHALPH SCREEN_HEIGHT/2
# define FRAMES_PER_SECOND 60
# define PITWO (M_PI * 2)
# define FT_FALSE (1 << 2)
# define FT_MAIN (1 << 0)
# define FT_MENU (1 << 1)
# define FT_GAME (1 << 2)

typedef struct		s_ft_rect
{
	int				x;
	int				y;
	int				width;
	int				hight;
	int				color;
	int				startx;
	int				starty;
	int				endx;
	int				endy;
	int				tmp;
}					t_ft_rect;

typedef struct		s_vector2d
{
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	int				color;
}					t_vector2d;

typedef struct		s_map
{
	int				fd;
	int				size;
	int				chkord;
	int				chk;
	int				**ceilingmap;
	int				**map;
	int				miniwidth;
	int				miniheight;
	char			*line;
}					t_map;

typedef struct		s_payer
{
	int				numbrays;
	double			rayscreenpos;
	double			rayviewdist;
	double			rayangle;
	double			stripwidth;
	double			viewdist;
	double			fov;
	double			rot;
	double			dir;
	int				walkr;
	int				walkl;
	int				walku;
	int				walkd;
	int				x;
	int				y;
	double			speed;
	double			moviespeed;
	double			rotspeed;
	double			posx;
	double			posy;
	double			camerax;
	double			dirx;
	double			diry;
	double			raydirx;
	double			raydiry;
	double			posz;
	double			planex;
	double			planey;
	double			sdistx;
	double			sdisty;
	double			ddistx;
	double			ddisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				side;
	int				mapx;
	int				mapy;
	double			olddirx;
	double			olddiry;
	double			oldplanex;
	double			oldplaney;
	int				hit;
}					t_player;

typedef struct		s_mp3
{
	int				play;
	int				next_song;
	int				previou_song;
	int				pause;
	int				stop;
	int				current_track;
	int				quant_tracks;
	char			**track_names;
	char			**track_name_and_path;
	Mix_Music		*track;
	int				quant_technicals;
	Mix_Music		*technical;
	int				quant_sounds;
	Mix_Chunk		**sounds;
}					t_mp3;

typedef struct		s_main
{
	int				ttf_quantity;
	SDL_Rect		pos[2];
	int				x;
	int				y;
	const char		*lables[2];
	int				selected[2];
	TTF_Font		*font;
	SDL_Color		color[2];
	SDL_Surface		*menus[2];
	SDL_Surface		*ptr_texture;
	int				status;
	int				lotary;
	int				quantity;
	char			**names;
	char			**names_with_path;
}					t_main;

typedef struct		s_menu
{
	SDL_Surface		*ptr_texture;
	int				status;
	int				lotary;
	int				quantity;
	char			**names;
	char			**names_with_path;
}					t_menu;

typedef struct		s_textures
{
	SDL_Surface		**ptr_texture;
	int				status;
	int				lotary;
	int				quantity;
	char			**names;
	char			**names_with_path;
}					t_textures;

typedef struct		s_win
{
	double			distwall;
	double			distplayer;
	int				floortexx;
	int				floortexy;
	double			floorxwall;
	double			floorywall;
	int				nfpresent;
	int				ofpresent;
	Uint32			time;
	t_map			map;
	int				coff;
	double			zoom;
	uint32_t		color_ptr;
	uint32_t		*pixel_ptr;
	uint32_t		*pixel_ptr_two;
	int				drawstart;
	int				drawend;
	int				texy;
	int				texx;
	int				color;
	double			x0;
	double			y0;
	double			sx;
	double			sy;
	int				tmpc;
	int				tmpk;
	double			mapw;
	double			maph;
	int				minimapscale;
	int				minimapcx;
	int				minimapcy;
	double			width;
	double			height;
	t_mp3			music;
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	t_main			main;
	t_menu			menu;
	t_textures		walls;
	t_textures		flats;
	t_textures		skybox;
	t_textures		ceiling;
	SDL_Window		*window;
	SDL_Surface		*screensurface;
	SDL_Surface		*minimapsurface;
	SDL_Surface		*screentmp;
	SDL_Renderer	*grenderer;
	SDL_Texture		*gtexture;
	SDL_Event		event;
	SDL_Event		mpthree;
	const Uint8		*currentkeystates;
	t_player		*player;
	int				statement;
	int				flag_menu_game;
	const uint8_t	*key;
	uint32_t		*image;
	uint32_t		*miniimage;
}					t_win;

void				ft_init_window(t_win *c_cl);
int					ft_init_images(t_win *c_cl);
int					ft_init_audios(t_win *c_cl);
int					ft_initialize_main_screen(t_win *sc_controller);
void				ft_initialize_player(t_win *sc_controller);
void				ft_initialize_stract(t_win *sc_controller);
char				**ft_doublerelloc(char **src, char *word, int size);
int					ft_truble_win(char *truble, t_win *c_cl);
int					ft_truble_img(char *truble, t_win *c_cl);
int					ft_truble_mix(char *truble, t_win *c_cl);
void				ft_error_main_sound(void);
void				ft_error_textures(char *str, char *strtow);
void				ft_error_minus(void);
void				ft_error_gen(char *av);
void				ft_error_hex(void);
void				ft_error_notdigit(void);
void				ft_error_gnl(t_win *params);
void				ft_error_alloc(void);
void				ft_error_len(void);
void				ft_error_buzz(void);
void				ft_error_dir(void);
void				ft_error_play_space(void);
void				ft_error_not_empty(void);
void				ft_error_ttf_init(void);
void				ft_error_folder(void);
void				ft_event_main(t_win *main);
void				ft_main_keyevent_down(t_win *c_ct);
void				ft_main_engin(t_win *c_ct);
void				ft_event_manu(t_win *c_ct);
void				ft_menu_execute(t_win *c_ct);
void				ft_menu_keyevent_up(t_win *c_ct);
void				ft_menu_keyevent_down(t_win *c_ct);
void				ft_menu_engin(t_win *c_ct);
void				ft_new_event_player(t_win *c_ct);
void				ft_game_execute(t_win *c_ct);
void				ft_turnleft(t_win *game);
void				ft_turnright(t_win *game);
void				ft_move_forward(t_win *game);
void				ft_move_backward(t_win *game);
void				ft_move(t_win *game);
void				ft_putplayer_sdl(t_win *game);
void				ft_drawminimap(t_win *game);
void				ft_additonal_engine(t_win *game);
void				ft_camera(t_win *game, int x);
void				ft_step_sidedist(t_win *game, int *x);
void				ft_review_hit_or_not(t_win *game);
void				ft_wall(t_win *game, int lineheight, int x);
void				ft_floor_hit(t_win *game, double wallx);
void				ft_ceiling_floor_viz(t_win *game, int x);
void				ft_set_text_position(t_win *main);
void				ft_music_player_keyevent_down(t_win *c_ct);
void				ft_malmix(t_win *c_cl);
void				ft_fill_playlist(t_win *c_cl, int quantity);
void				ft_bzero_music_params(t_win *c_cl);
void				ft_music_player_keyevent_down(t_win *c_ct);
void				ft_music_execute(t_win *c_ct);
int					ft_music_play(t_win *c_cl);
int					ft_music_previous(t_win *c_ct);
int					ft_music_next(t_win *c_ct);
int					ft_hold_music(t_win *c_cl);
void				ft_draw_wall(t_win *game, int wall_side, int x, int y);
void				ft_line_direct(t_win *game);
void				ft_fill_rect(t_ft_rect *rect, t_win *game);
int					ft_rgb(int r, int g, int b, int	transp);
void				ft_visualization(t_win *c_ct);
void				ft_map_parsing(char *av, t_win *c_cl);
void				ft_main(t_win *main);
int					ft_showmenu(t_win *main);
void				ft_menu(t_win *menu);
void				ft_game_core(t_win *game);
int					ft_count_files(char *path, t_win *c_cl);
void				free_darray(char **src, int size);
char				**ft_doub_part_one(char *word, char *path);
char				**ft_doub_part_two(char **src, char *word,\
int size, char *path);
char				**ft_doub_one(char *word);
char				**ft_doub_two(char **src, char *word, int size);
char				**ft_doublerelloc_and_path(char **src, char *word,\
int size, char *path);
char				**ft_doublerelloc(char **src, char *word, int size);
void				ft_review_needed_folders(char *path, t_win *c_cl);
void				ft_help_count(char *path, t_win *c_cl,\
struct dirent *entry, int file_count);
void				ft_bzero_move_params(t_win *game);
void				ft_keyboard_handle(t_win *c_ct);
void				ft_mouse_handle(t_win *c_ct);
void				ft_core(t_win *c_ct);
SDL_Surface			*ft_get_img(char *path);
int					is_regular_file(const char *path);
int					ft_memstcol(t_win *c_cl);
int					ft_memstcmal(t_win *c_cl);
int					ft_validval(char **maps, t_win *par);
int					ft_nblen(int tmpd);
int					ft_validhex(char *map, int tmpd);
int					ft_right_symbol(char *s, int from);
int					ft_borders(t_win *c_cl);
void				ft_filltabcord(t_win *c_cl);
void				ft_count_ethalon(t_win *params, char **maps, int *i);
void				ft_help_function(t_win *c_cl, char *iter);
void				sdl_close(t_win *sc_control);
void				ft_draw_c_f(t_win *game, int x, int y, double currentdist);
void				ft_line_sdl(t_vector2d *vector, t_win *game);
#endif
