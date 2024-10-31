#include <stdio.h>
static int total_step = 0;
void hanoi_tower(int disk_num) {
  if (disk_num == 1) {
    total_step++;
    return;
  }
  hanoi_tower(disk_num - 1);
  total_step++;
  hanoi_tower(disk_num - 1);
}

int main() {
  hanoi_tower(3);
  printf("%d", total_step);
}