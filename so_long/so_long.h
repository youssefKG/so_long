#ifndef SO_LONG_HEADER
#define SO_LONG_HEADER

#define WIN1_SX  700
#define WIN1_SY 700

typedef struct Img {
  void *img;
  char *data;
  int width;
  int height;
  int size_line;
  int bpp;
  int endiant;
  char *path;
} s_img;

typedef struct Win {
  void *win;
  int width;
  int height;
} s_win;

typedef struct Player {
  s_img img;
} s_player;

typedef struct Map {
  char **map;
  int cols;
  int rows;
} s_map;


// void ft_draw_box(void *wind, int x, int y, int size, int color);
void ft_scale_img(s_img *tar_img, s_img *orig_img);
void ft_init_img(void *mlx, s_img *img, int width, int height);
void ft_render_img(void *mlx, void *wind, s_img *img, char *filename, int x, int y);

#endif // SO_LONG_HEADER
