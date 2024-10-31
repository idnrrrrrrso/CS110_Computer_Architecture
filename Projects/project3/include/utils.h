#ifndef __UTILS_H
#define __UTILS_H

#include "gd32vf103_libopt.h"

enum {
  JOY_LEFT = 1,
  JOY_DOWN = 2,
  JOY_RIGHT = 3,
  JOY_UP = 0,
  JOY_CTR = 4,
  BUTTON_1 = 5,
  BUTTON_2 = 6
};

int Get_Button(int ch);

int Get_BOOT0(void);

#endif
