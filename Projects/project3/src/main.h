#ifndef MAIN_GAME
#define MAIN_GAME

// #include "assembly/splash_screen.h"
#include "lcd/lcd.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TRACE 20

bool splash_screen = true;
bool game_started = false;
bool select_difficulty = false;

typedef struct {
  int player_upward_speed;   // 玩家上升速度
  int gravity;               // g,决定玩家下降速度
  int wall_vertical_space;   // 墙壁之间的垂直间距
  int wall_horizontal_space; // 墙壁之间的水平间距
  int wall_speed;            // 墙壁移动速度
} Difficulty;

Difficulty easy = {.player_upward_speed = -6,
                   .gravity = 2,
                   .wall_vertical_space = 50,
                   .wall_horizontal_space = 35,
                   .wall_speed = 1};

Difficulty hard = {.player_upward_speed = -10,
                   .gravity = 2,
                   .wall_vertical_space = 35,
                   .wall_horizontal_space = 35,
                   .wall_speed = 1};

Difficulty game_difficulty;

bool which_difficulty = 0;

typedef struct {
  int position_x;
  int position_y;
  int velocity;
} Player;

Player game_player = {.position_x = 20, .position_y = 90, .velocity = 0};
Player prev_game_player = {.position_x = 20, .position_y = 90, .velocity = 0};

int player_life = 999;
int prev_player_life = 999;
int player_score = 0;
int prev_player_score = 0;
int player_reborn = 0;

typedef struct {
  int x;
  int y;
} Wall;

Wall walls[3];
Wall prev_walls[3];

typedef struct {
  int x;
  int y;
} TracePoint;

TracePoint trace[NUM_TRACE];
TracePoint prev_trace[NUM_TRACE];

// void update_lcd();

void Inp_init(void);

void IO_init(void);

int show_splash_screen(int pos, int past_pos);

void draw_difficulty_screen();

void init_game();

void handle_input();

void update_player();

void game_reset();

void draw_player(Player *player, u16 color);

void init_walls();

void draw_walls(Wall (*walls)[3], u16 color);

void update_walls();

void check_collision();

void update_score();

void update_trace();

void init_trace();

void draw_trace(TracePoint (*trace)[NUM_TRACE], u16 color);

void draw_score_life();

void draw_game();

int max(int a, int b, int c);

#endif // MAIN_GAME