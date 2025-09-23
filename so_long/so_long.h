#ifndef SO_LONG_HEADER
#define SO_LONG_HEADER

typedef struct Img {
  void *img;
  char *data;
  int size_line;
  int bpp;
  int width;
  int height;
  int endiant;
  char *path;
} s_img;


// void ft_draw_box(void *wind, int x, int y, int size, int color);
void ft_scale_img(s_img *tar_img, s_img *orig_img);
void ft_init_img(void *mlx, s_img *img, int width, int height);

#endif // SO_LONG_HEADER
