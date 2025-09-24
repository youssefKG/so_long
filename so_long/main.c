#include "../mlx.h"
#include "./so_long.h"
#include "map.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TITLE "totib"

void *mlx;

void ft_printmap(char **s, int cols, int rows);
int main() {
  s_win win;
  s_img player;
  s_img *collectibles;
  s_map map;

  map.map = ft_parse_map("./maps/map2.per", &map.rows, &map.cols);
  ft_printmap(map.map, map.cols, map.rows);
  mlx = mlx_init();
  printf(" => Connection...\n");
  if (!mlx) {
    printf("connection failed!\n");
    return 0;
  }
  win.win = mlx_new_window(mlx, WIN1_SX, WIN1_SY, TITLE);
  ft_render_map(mlx, win.win, map);
  while (1) {
    sleep(1);
  }
}
