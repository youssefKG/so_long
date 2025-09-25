#ifndef MAP_HEADER
#define MAP_HEADER

#include "so_long.h"
char **ft_parse_map(char *path, int *col, int* row);
void ft_init_player(s_player *palyer, s_map map);
#endif
