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
  s_player player;
  s_map map;

  map.map = ft_parse_map("./maps/map3.per", &map.cols, &map.rows);
  ft_set_player_start_position(&player, map);
  ft_printmap(map.map, map.cols, map.rows);
  mlx = mlx_init();
  printf(" => Connection...\n");
  if (!mlx) {
    printf("connection failed!\n");
    return 0;
  }
  ft_init_window(mlx, &win, map, "hello");
  ft_render_map(mlx, &win, map);
  while (1) {
    sleep(30);
  }
}

void ft_printmap(char **s, int cols, int rows) {
  int i;
  int j;

  i = 0;
  j = 0;

  printf("printf parser map\n");
  printf("row %d\n", rows);
  printf("col %d\n", cols);
  while (i < rows) {
    j = 0;
    while (j < cols) {
      printf("%c", s[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}
