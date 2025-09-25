#ifndef OBJECT_HEADER
#define OBJECT_HEADER
#include "so_long.h"
void ft_create_object(s_img *object, void *mlx, int w, int h, char object_type);
s_img **ft_init_objects(void *mlx, s_map map, int w, int h);
void ft_render_objects(void *mlx, s_win *win, s_img **objects, s_map map);

#endif
