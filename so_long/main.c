#include "../mlx.h"
#include "./so_long.h"
#include <stdio.h>
#include <unistd.h>

#define WIN1_SX 882
#define WIN1_SY 882
#define TITLE "totib"

void *mlx;

int main() {
  void *win;
  s_img fish;
  s_img file_fish;

  mlx = mlx_init();
  printf(" => Connection...\n");
  if (!mlx) {
    printf("connection failed!\n");
    return 0;
  }
  win = mlx_new_window(mlx, WIN1_SX, WIN1_SY, TITLE);
  if (!win) {
    printf("Error: faild to init the wind1\n");
    return 1;
  }
  ft_init_img(mlx, &fish, 600, 600);
  file_fish.img = mlx_xpm_file_to_image(mlx, "./open.xpm", &file_fish.width,
                                        &file_fish.height);
  file_fish.data = mlx_get_data_addr(file_fish.img, &file_fish.bpp,
                                     &file_fish.size_line, &file_fish.endiant);
  ft_scale_img(&fish, &file_fish);
  mlx_put_image_to_window(mlx, win, fish.img, 0, 0);
  while (1) {
    sleep(1);
  }
}
