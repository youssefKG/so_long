
#include "so_long.h"
#include <stdlib.h>
s_img **ft_init_objects(s_map map) {
  s_img **objects;
  int i;
  int j;

  objects = (s_img **)malloc(sizeof(s_img *) * map.rows);

  while (i < map.rows) {
    objects[i] = (s_img *)malloc(sizeof(s_img) * map.cols);
    i++;
  }
  i = 0;

  return objects;
}
