#ifndef MAP_HEADER
#define MAP_HEADER

#include "so_long.h"
void ft_render_map(void *mlx, s_win *win, s_map map);
char **ft_parse_map(char *path, int *col, int* row);
void ft_set_player_start_position(s_player *palyer, s_map map);
#endif
