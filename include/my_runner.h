/*
** EPITECH PROJECT, 2017
** my_runner.h
** File description:
** include
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <SFML/Graphics.h>
#include "graphical.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define COLISION_UP 1
#define COLISION_RIGHT 2
#define COLISION_DOWN 3
#define LOOSE -1
#define NONE 0
#define WIN 1
#define SOUND 0
#define MUSIC 1
#define VALUES "12F"

enum type {
	BACK_FRONT,
	BACK_MIDDLE,
	BACK_BACK,
	SONIC,
	SUPER_SONIC,
	SONIC_MENU,
	CADRE,
	GROUND,
	GROUND2,
	PIKE,
	FLAG,
};

enum type_sound {
	GREEN_HILL,
	MENU,
	HURT,
	WIN_S,
	LOOSE_S,
	JUMP,
};

enum type_text {
	TEXT_END,
	TEXT_SCORE,
};

struct sounds {
	enum type_sound type;
	sfMusic *music;
	sfSoundBuffer *sound_buff;
	sfSound *sound;
};
typedef struct sounds sounds;

struct game_object {
	enum type type;
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f position;
	sfIntRect rect;
	s_clock clock_mov;
	sfVector2f offset;
	void *ptr_move;
};
typedef struct game_object game_object;

struct window {
	sfVideoMode mode;
	sfRenderWindow *window;
	sfVector2i position_win;
	sfIntRect rect;
};
typedef struct window s_window;

struct s_text {
	sfFont *font;
	sfText *text;
};
typedef struct s_text text;

struct s_global {
	game_object **ground;
	game_object **sprites;
	s_window window;
	sounds **music;
	text **texts;
	int level;
	int score;
	int best_score;
	int alpha;
	int offset_alpha;
};
typedef struct s_global global;

int my_runner(char *filepath);
struct game_object *create_object(const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect, sfVector2f);
s_window initialisation_window(void);
int analyse_events(global *data, sfEvent eve);
void close_window(sfRenderWindow *window);
void destroy_object(game_object *obj);
int game_loop(global *data);
game_object **initialise_all_sprites(void);
game_object *initialisation_back(int type, char *filepath, sfVector2f position);
text *create_text(char *filepath, sfVector2f position, int size);
game_object **destroy_all_sprites(game_object **sprites);
int draw_sonic(game_object **sprites, game_object **ground, s_window *window, float limit);
sounds **destroy_all_music(sounds **music);
sounds **initialise_all_music(void);
int recup_arg(char *av);
int option_h(void);
int count_size_struct(char **map);
game_object **recup_struct(char *filepath);
int open_file(char const *filepath);
int count_size(char *filepath);
char **recup_map(int size, char *filepath);
game_object **destroy_ground(game_object **ground);
int check_ground_struct(game_object **ground, int size);
game_object *collision_ground(game_object *sonic, game_object **ground);
int precise_colision(game_object *sonic, game_object *ground);
game_object **put_end_lvl(game_object **ground, int size);
int fall_detection(game_object **sprites);
int check_chara(char letter);
game_object **ground_map(game_object **ground, int *nbr_stru, sfVector2i position);
game_object **pike_map(game_object **ground, int *nbr_stru, sfVector2i position);
game_object **flag_map(game_object **ground, int *nbr_stru, sfVector2i position);
int animation_win(global *data);
void draw_back(game_object *back, s_window *window, int offset);
int animation_loose(global *data);
void super_sonic(s_window *window, game_object *sprites, float limit);
global *destroy_global(global *all);
text **destroy_all_text(text **current);
global *initialisation_all_global(char *filepath);
text **create_all_texts(void);
char *my_putnbr_str(int nbr);
void print_score(global *data, int score, int x, int y);
void print_text(global *data, char *str, int size, sfVector2f position);
global *re_initialisation(global *data);
void manage_lvl(global *data);
void print_enter_alpha(global *data, sfVector2f position, int size);
void draw_ground(game_object **ground, s_window *window, int speed);
game_object **initialisation_sprites_menu(game_object **sprites);
void menu_loop(global *data);
void check_window_size(sfRenderWindow *window);
void pause_menu(global *data);

#endif