#include "./minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <linux/limits.h>
#include <stdlib.h>

void ft_create_object(s_img *object, void *mlx, int w, int h, char object_type);
char *ft_strdup(char *s);
char *ft_get_object_img_path(char object_type);

s_img **ft_init_objects(void *mlx, s_map map, int w, int h) {
  s_img **objects;
  int i;
  int j;

  objects = (s_img **)malloc(sizeof(s_img *) * map.rows);
  if (!objects)
    return NULL;
  i = 0;
  while (i < map.cols) {
    objects[i] = (s_img *)malloc(sizeof(s_img) * map.cols);
    i++;
  }
  i = 0;
  while (i < map.rows) {
    j = 0;
    while (j < map.cols) {
      ft_create_object(&objects[i][j], mlx, w, h, map.map[i][j]);
      j++;
    }
    i++;
  }
  return objects;
}

void ft_create_object(s_img *object, void *mlx, int w, int h,
                      char object_type) {
  s_img original_img;
  char *object_img_path;
  object->width = w;
  object->height = h;
  object->img = mlx_new_image(mlx, object->width, object->height);
  object->data = mlx_get_data_addr(object->img, &object->bpp,
                                   &object->size_line, &object->endiant);
  object_img_path = ft_get_object_img_path(object_type);
  original_img.img = mlx_xpm_file_to_image(
      mlx, object_img_path, &original_img.width, &original_img.height);
  original_img.data =
      mlx_get_data_addr(original_img.img, &original_img.bpp,
                        &original_img.size_line, &original_img.endiant);
  ft_scale_img(object, &original_img);
  mlx_destroy_image(mlx, original_img.img);
  free(object_img_path);
}

void ft_render_objects(void *mlx, s_win *win, s_img **objects, s_map map) {
  int i;
  int j;
  int y;
  int width;
  int height;

  y = 0;
  width = win->width / map.cols;
  height = win->height / map.rows;
  i = 0;
  while (i < map.rows) {
    j = 0;
    while (j < map.cols) {
      mlx_put_image_to_window(mlx, win->win, objects[i][j].img, j * width, y);
      j++;
    }
    y += height;
    i++;
  }
}

char *ft_get_object_img_path(char object_type) {
  if (object_type == '1')
    return ft_strdup("./images/wall.xpm");
  else if (object_type == '0')
    return ft_strdup("./images/background_solid_grass.xpm");
  else if (object_type == 'P')
    return ft_strdup("./images/player.xpm");
  else if (object_type == 'C')
    return ft_strdup("./open.xpm");
  else if (object_type == 'E')
    return ft_strdup("./images/sign_exit.xpm");
  return NULL;
}

char *ft_strdup(char *s) {
  char *result;
  int s_len;

  s_len = ft_strlen(s);
  result = (char *)malloc(sizeof(char) * (s_len + 1));
  if (!result)
    return NULL;
  result[s_len] = '\0';
  while (*s) {
    *result = *s;
    result++;
    s++;
  }
  return result - s_len;
}
