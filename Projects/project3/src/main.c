#include "main.h"
// #include "assembly/splash_screen.h"

int main(void) {
  IO_init();
  LCD_Clear(BLACK);

  while (1) {
    uint64_t start_mtime, delta_mtime;
    uint64_t tmp = get_timer_value();
    do {
      start_mtime = get_timer_value();
    } while (start_mtime == tmp);

    if (splash_screen) {
      int static past_pos = 0;
      int static pos = 0;

      pos = show_splash_screen(pos, past_pos);
      past_pos = pos;

      if (Get_Button(JOY_CTR) || Get_Button(JOY_DOWN) || Get_Button(JOY_LEFT) ||
          Get_Button(JOY_RIGHT) || Get_Button(JOY_UP) || Get_Button(BUTTON_1) ||
          Get_Button(BUTTON_2)) {
        splash_screen = false;
        select_difficulty = true;
        LCD_Clear(BLACK);
        delay_1ms(300);
      }
    } else if (select_difficulty) {
      draw_difficulty_screen();
    } else if (game_started) {
      handle_input();
      update_player();
      update_walls();
      update_trace();
      draw_game();
      check_collision();
      update_score();
      update_trace();
    }

    do {
      delta_mtime = get_timer_value() - start_mtime;
    } while (delta_mtime <
             (SystemCoreClock / 4000.0 * 100)); // 每100毫秒(0.1秒一帧
  }
}

void Inp_init(void) {
  rcu_periph_clock_enable(RCU_GPIOA);
  rcu_periph_clock_enable(RCU_GPIOC);

  gpio_init(GPIOA, GPIO_MODE_IPD, GPIO_OSPEED_50MHZ,
            GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
  gpio_init(GPIOC, GPIO_MODE_IPD, GPIO_OSPEED_50MHZ,
            GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);
}

void IO_init(void) {
  Inp_init(); // inport init
  Lcd_Init(); // LCD init
}

// use 300 lines of RISC-V instructions
// int show_splash_screen(int pos, int past_pos) {
//   int direction = 1;
//   if (pos == 5) {
//     direction = -1;
//   }
//   pos += direction;
//   LCD_ShowString(15, 20 + past_pos * 3, (u8 *)"Flappy", BLACK);
//   LCD_ShowString(25, 40 + past_pos * 3, (u8 *)"Bird", BLACK);
//   LCD_ShowString(15, 20 + pos * 3, (u8 *)"Flappy", WHITE);
//   LCD_ShowString(25, 40 + pos * 3, (u8 *)"Bird", WHITE);

//   return pos;
// }

void draw_difficulty_screen() {
  LCD_ShowString(15, 20, (u8 *)"Select", WHITE);
  static bool sleep = 0;
  if (Get_Button(JOY_DOWN) || Get_Button(JOY_UP)) {
    which_difficulty = !which_difficulty;
    sleep = 1;
    LCD_ShowString(5, 80, (u8 *)"> Easy", BLACK);
    LCD_ShowString(5, 100, (u8 *)"> Hard", BLACK);
  } else {
    sleep = 0;
  }

  if (which_difficulty == 0) {
    LCD_ShowString(5, 80, (u8 *)"> Easy", GREEN);
    LCD_ShowString(5, 100, (u8 *)"  Hard", WHITE);
    if (sleep)
      delay_1ms(300);
  } else {
    LCD_ShowString(5, 80, (u8 *)"  Easy", WHITE);
    LCD_ShowString(5, 100, (u8 *)"> Hard", GREEN);
    if (sleep)
      delay_1ms(300);
  }
  if (Get_Button(JOY_CTR)) {
    game_difficulty = which_difficulty ? hard : easy;
    select_difficulty = false;
    game_started = true;
    init_game();
  }
}

void init_game() {
  LCD_Clear(BLACK);
  init_walls();
  init_trace();
  LCD_DrawRectangle(1, 39, LCD_W - 2, 159, GRAYBLUE);
  LCD_ShowString(5, 5, (u8 *)"Score", WHITE);
  LCD_ShowString(5, 20, (u8 *)"Life", WHITE);
}

void init_trace() {
  for (int i = 0; i < NUM_TRACE; i++) {
    prev_trace[i].x = 0;
    prev_trace[i].y = 0;
    trace[i].x = 0;
    trace[i].y = 0;
  }
}

void game_reset() {
  delay_1ms(300);
  player_reborn = 15;
  game_player.position_x = 20;
  game_player.position_y = 90;
  game_player.velocity = 0;
  draw_trace(&prev_trace, BLACK);
  draw_trace(&trace, BLACK);
  init_trace();
}

void handle_input() {
  if (Get_Button(JOY_CTR) || Get_Button(JOY_DOWN) || Get_Button(JOY_LEFT) ||
      Get_Button(JOY_RIGHT) || Get_Button(JOY_UP) || Get_Button(BUTTON_1) ||
      Get_Button(BUTTON_2)) {
    game_player.velocity = game_difficulty.player_upward_speed;
  } else {
    game_player.velocity += game_difficulty.gravity;
  }
}

void update_player() {
  game_player.position_y += game_player.velocity;
  if (game_player.position_y < 41) {
    game_player.position_y = 41;
  }
  if (game_player.position_y > LCD_H - 3) {
    game_player.position_y = LCD_H - 3;
  }
}

void draw_player(Player *player, u16 color) {
  LCD_DrawPoint_big(player->position_x, player->position_y, color);
}

void init_walls() {
  for (int i = 0; i < 3; i++) {
    walls[i].x = 39 + i * game_difficulty.wall_horizontal_space;
    walls[i].y = rand() % 80 + 50;
  }
}

void draw_walls(Wall (*walls)[3], u16 color) {
  for (int i = 0; i < 3; i++) {
    if ((*walls)[i].x < LCD_W - 2) {
      LCD_DrawLine((*walls)[i].x, 40, (*walls)[i].x, (*walls)[i].y, color);
      LCD_DrawLine((*walls)[i].x,
                   (*walls)[i].y + game_difficulty.wall_vertical_space,
                   (*walls)[i].x, 157, color);
    }
  }
}

void update_walls() {
  for (int i = 0; i < 3; i++) {
    walls[i].x -= game_difficulty.wall_speed * 2;
    if (walls[i].x < 2) {
      walls[i].x = max(walls[0].x, walls[1].x, walls[2].x) +
                   game_difficulty.wall_horizontal_space;
      walls[i].y = rand() % 80 + 50;
    }
  }
}

void check_collision() {
  // 是否和墙壁碰撞
  if (player_reborn != 0)
    return;

  if (game_player.position_y <= 41 || game_player.position_y >= LCD_H - 3) {
    prev_player_life = player_life;
    player_life--;
    game_reset();
    return;
  }

  // 是否和墙碰撞
  for (int i = 0; i < 3; i++) {
    if ((game_player.position_x >= walls[i].x - 1 &&
         game_player.position_x <= walls[i].x + 1) &&
        (game_player.position_y <= walls[i].y ||
         game_player.position_y >=
             walls[i].y + game_difficulty.wall_vertical_space)) {
      prev_player_life = player_life;
      player_life--;
      game_reset();
      return;
    }
  }
}

void update_score() {
  for (int i = 0; i < 3; i++) {
    if (walls[i].x == game_player.position_x - 1 ||
        walls[i].x == game_player.position_x) {
      prev_player_score = player_score;
      player_score++;
      return;
    }
  }
}

void draw_score_life() {
  if (prev_player_score != player_score) {
    LCD_ShowNum(45, 5, prev_player_score, 3, BLACK);
  }
  LCD_ShowNum(45, 5, player_score, 3, WHITE);
  if (prev_player_life != player_life) {
    LCD_ShowNum(45, 20, prev_player_life, 3, BLACK);
  }
  LCD_ShowNum(45, 20, player_life, 3, WHITE);
}

void update_trace() {
  trace[0].x = game_player.position_x;
  trace[0].y = game_player.position_y;
  for (int i = NUM_TRACE - 1; i > 0; i--) {
    trace[i] = trace[i - 1];
    trace[i].x -= game_difficulty.wall_speed;
  }
}

void draw_trace(TracePoint (*trace)[NUM_TRACE], u16 color) {
  for (int i = 0; i < NUM_TRACE; i++) {
    if ((*trace)[i].x > 2) {
      // LCD_DrawLine((*trace)[i].x, (*trace)[i].y, (*trace)[i + 1].x,
      //  (*trace)[i + 1].y, color);
      LCD_DrawPoint((*trace)[i].x, (*trace)[i].y, color);
    }
  }
}

void draw_game() {
  // 哎我也知道这里有的在这里update有的在updateu函数里update很混乱但是！能跑就行。。。

  draw_player(&prev_game_player, BLACK);
  if (player_reborn == 0) {
    draw_player(&game_player, RED);
  } else {
    player_reborn--;
    draw_player(&game_player, GREEN);
  }
  prev_game_player = game_player;

  draw_walls(&prev_walls, BLACK);
  draw_walls(&walls, WHITE);
  for (int i = 0; i < 3; i++) {
    prev_walls[i] = walls[i];
  }

  draw_trace(&prev_trace, BLACK);
  draw_trace(&trace, GRAY);
  for (int i = 0; i < NUM_TRACE; i++) {
    prev_trace[i] = trace[i];
  }

  draw_score_life();
}

int max(int a, int b, int c) {
  int max_val = a;
  if (b > max_val)
    max_val = b;
  if (c > max_val)
    max_val = c;
  return max_val;
}