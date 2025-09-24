#ifndef MAP_HEADER
#define MAP_HEADER

#include "so_long.h"
void ft_render_map(void *mlx, void *win, s_map map);
char **ft_parse_map(char *path, int *col, int* row);
#endif
