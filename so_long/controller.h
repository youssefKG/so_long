#ifndef CONTROLLER_HEADER
#define CONTROLLER_HEADER

#include "so_long.h"
void ft_move_down(void *mlx, s_win *win, s_img **objects, s_map *map,
                  s_player *player);
void ft_move_right(void *mlx, s_win *win, s_img **objects, s_map *map,
                   s_player *player);
void ft_move_up(void *mlx, s_win *win, s_img **objects, s_map *map,
                   s_player *player);
void ft_move_left(void *mlx, s_win *win, s_img **objects, s_map *map,
                   s_player *player);
#endif
