#include "../mlx.h"
#include "./so_long.h"
#include "map.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TITLE "totib"

void *mlx;

int main() {
  void *win;
  s_img imgs[20];
  int i;
  int start;

  mlx = mlx_init();
  printf(" => Connection...\n");
  if (!mlx) {
    printf("connection failed!\n");
    return 0;
  }
  win = mlx_new_window(mlx, WIN1_SX, WIN1_SY, TITLE);
  ft_render_map(mlx, win, "./maps/map2.per");
  while (1) {
    sleep(1);
  }
}
