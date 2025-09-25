#include "objects.h"
#include "so_long.h"
#include <stdio.h>

void ft_swap_object(s_img *obj1, s_img *obj2) {
  s_img temp_obj;
  temp_obj = *obj1;
  *obj1 = *obj2;
  *obj2 = temp_obj;
}

void ft_swap_map_position(char *p1, char *p2) {
  char temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void ft_move_up(void *mlx, s_win *win, s_img **objects, s_map *map,
                s_player *player) {
  char next_obj;
  int x;
  int y;

  x = player->x;
  y = player->y;
  next_obj = map->map[y - 1][x];
  if (next_obj == '1') {
    return;
  } else if (next_obj == 'C') {
    ft_create_object(&objects[y - 1][x], mlx, 50, 50, '0');
  }
  ft_swap_object(&objects[y][x], &objects[y - 1][x]);
  ft_swap_map_position(&map->map[y][x], &map->map[y - 1][x]);
  player->y = y - 1;
  ft_render_objects(mlx, win, objects, *map);
}

void ft_move_down(void *mlx, s_win *win, s_img **objects, s_map *map,
                  s_player *player) {
  char next_obj;
  int x;
  int y;

  x = player->x;
  y = player->y;

  next_obj = map->map[y + 1][x];
  if (next_obj == '1') {
    return;
  } else if (next_obj == 'C') {
    ft_create_object(&objects[y + 1][x], mlx, 50, 50, '0');
  }
  ft_swap_object(&objects[y][x], &objects[y + 1][x]);
  ft_swap_map_position(&map->map[y][x], &map->map[y + 1][x]);
  player->y = y + 1;
  ft_render_objects(mlx, win, objects, *map);
}

void ft_move_right(void *mlx, s_win *win, s_img **objects, s_map *map,
                   s_player *player) {
  int x;
  int y;
  x = player->x;
  y = player->y;
  // check if is valid move
  char next_cell;
  next_cell = map->map[player->y][player->x + 1];
  if (next_cell == '1') {
    printf("You connect surpass a wall\n");
    return;
  } else if (next_cell == 'C')
    ft_create_object(&objects[y][x + 1], mlx, 50, 50, '0');

  ft_swap_object(&objects[y][x], &objects[y][x + 1]);
  ft_swap_map_position(&map->map[y][x], &map->map[y][x + 1]);
  player->x = x + 1;
  ft_render_objects(mlx, win, objects, *map);
}

void ft_move_left(void *mlx, s_win *win, s_img **objects, s_map *map,
                  s_player *player) {
  char next_obj;
  int x;
  int y;

  x = player->x;
  y = player->y;
  next_obj = map->map[y][x - 1];

  if (next_obj == '1') {
    printf("you cannot surpass the wall! \n");
    return;
  }
  if (next_obj == 'C') {
    ft_create_object(&objects[y][x - 1], mlx, 50, 50, '0');
  }
  ft_swap_object(&objects[y][x], &objects[y][x - 1]);
  ft_swap_map_position(&map->map[y][x], &map->map[y][x - 1]);
  player->x = x - 1;
  ft_render_objects(mlx, win, objects, *map);
}
