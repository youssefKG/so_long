#include "../mlx.h"
#include "../mlx_int.h"
#include "./so_long.h"
#include "controller.h"
#include "map.h"
#include "objects.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TITLE "totib"

#define DOWN_KEY 65364
#define UP_KEY 65362
#define RIGHT_KEY 65363
#define LEFT_KEY 65361

s_player player;
s_win win;
s_map map;
s_img **objects;
void *mlx;

int key_win(int key, void *p) {
  if (key == DOWN_KEY)
    ft_move_down(mlx, &win, objects, &map, &player);
  else if (key == UP_KEY)
    ft_move_up(mlx, &win, objects, &map, &player);
  else if (key == RIGHT_KEY)
    ft_move_right(mlx, &win, objects, &map, &player);
  else if (key == LEFT_KEY)
    ft_move_left(mlx, &win, objects, &map, &player);
  return 0;
}

void ft_printmap(char **s, int cols, int rows);

int main() {

  mlx = mlx_init();
  map.map = ft_parse_map("./maps/map3.per", &map.cols, &map.rows);
  ft_printmap(map.map, map.cols, map.rows);
  ft_set_player_start_position(&player, map);
  printf("player x %d %d\n", player.x, player.y);
  objects = ft_init_objects(mlx, map, 50, 50);

  printf(" => Connection...\n");
  if (!mlx) {
    printf("connection failed!\n");
    return 0;
  }
  ft_init_window(mlx, &win, map, "hello");
  ft_render_objects(mlx, &win, objects, map);
  mlx_key_hook(win.win, key_win, 0);
  // mlx_hook(win.win, MotionNotify, PointerMotionMask, mouse_win, 0);
  mlx_loop(mlx);
}

void ft_printmap(char **s, int cols, int rows) {
  int i;
  int j;

  i = 0;
  j = 0;
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

// void ft_printfobjs(s_img **objs, int cols, int rows) {
//   int i;
//   int j;
//
//   i = 0;
//   j = 0;
//   while (i < rows) {
//     j = 0;
//     while (j < cols) {
//       printf("%d ", objs[i][j].height);
//       j++;
//     }
//     printf("\n");
//     i++;
//   }
// }
