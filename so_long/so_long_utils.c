#include "../mlx.h"
#include "../mlx_int.h"
#include "so_long.h"

void ft_scale_img(s_img *tar_img, s_img *orig_img) {
  int x;
  int y;
  double y_scale_factor;
  double x_scale_factor;
  int orig_x;
  int orig_y;
  unsigned int color;

  y_scale_factor = (double)orig_img->height / tar_img->height;
  x_scale_factor = (double)orig_img->width / tar_img->width;
  y = 0;
  while (y < tar_img->height) {
    x = 0;
    while (x < tar_img->width) {
      orig_x = (int)(x * x_scale_factor);
      orig_y = (int)(y * y_scale_factor);
      color =
          *(unsigned int *)(orig_img->data + ((orig_y * orig_img->size_line) +
                                              orig_x * (orig_img->bpp) / 8));
      *(unsigned int *)(tar_img->data + (y * tar_img->size_line +
                                         x * (tar_img->bpp / 8))) = color;
      x++;
    }
    y++;
  }
}

void ft_init_img(void *mlx, s_img *img, int width, int height) {
  img->img = mlx_new_image(mlx, width, height);
  img->data =
      mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endiant);
  img->width = width;
  img->height = height;
  img->path = NULL;
}

void ft_draw_box(void *mlx, void *win, int x, int y, int size, int color) {
  int i;
  int j;

  j = 0;
  i = 0;
  while (i < size) {
    j = 0;
    while (j < size) {
      mlx_pixel_put(mlx, win, x + i, y + j, color);
      j++;
    }
    i++;
  }
}
