#include "./get_next_line/get_next_line.h"
#include "get_next_line/get_next_line_bonus.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

void ft_render_empty_space(void *mlx, void *win, int width, int height, int x,
                           int y);
void ft_render_exit(void *mlx, void *win, int width, int height, int x, int y);
void ft_render_wall(void *mlx, void *win, int width, int height, int x, int y);
void ft_render_collectible(void *mlx, void *win, int width, int height, int x,
                           int y);
void ft_render_player(void *mlx, void *win, int width, int height, int x,
                      int y);

void ft_parse_map(int *col, int *row, char *path) {
  int map_fd = open(path, O_RDONLY);
  char *line;

  *col = 0;
  *row = 0;
  line = get_next_line(map_fd);
  while (line[*col] && line[*col] != '\n') {
    (*col)++;
  }
  while (line) {
    line = get_next_line(map_fd);
    (*row)++;
  }
}

void ft_render_map(void *mlx, void *win, char *path) {
  char *line;
  int map_fd = open(path, O_RDONLY);
  int map_len;
  int width;
  int height;
  int i;
  int j;
  int col;
  int row;

  i = 0;
  j = 0;

  ft_parse_map(&col, &row, path);
  char c;
  int y = 0;
  while ((line = get_next_line(map_fd))) {
    map_len = ft_strlen(line);
    width = WIN1_SX / col;
    height = WIN1_SY / row;
    j = 0;
    while (line[j] && line[j] != '\n') {
      if (line[j] == '0')
        ft_render_empty_space(mlx, win, width, width, width * j, y);
      if (line[j] == '1')
        ft_render_wall(mlx, win, width, width, width * j, y);
      else if (line[j] == 'C')
        ft_render_collectible(mlx, win, width, width, width * j, y);
      else if (line[j] == 'E')
        ft_render_exit(mlx, win, width, width, width * j, y);
      else if (line[j] == 'P') {
        ft_render_wall(mlx, win, width, width, width * j, y);
        ft_render_player(mlx, win, width, width, width * j, y);
      }

      write(1, &line[j], 1);
      j++;
    }
    printf("\n");
    i++;
    y += width;
  }
}

void ft_render_wall(void *mlx, void *win, int width, int height, int x, int y) {
  s_img wall;
  ft_init_img(mlx, &wall, width, height);
  ft_render_img(mlx, win, &wall, "./images/wall.xpm", x, y);
}

void ft_render_empty_space(void *mlx, void *win, int width, int height, int x,
                           int y) {
  s_img empty_space;
  ft_init_img(mlx, &empty_space, width, height);
  ft_render_img(mlx, win, &empty_space, "./images/background_solid_grass.xpm",
                x, y);
}
void ft_render_collectible(void *mlx, void *win, int width, int height, int x,
                           int y) {
  s_img collectible;
  ft_init_img(mlx, &collectible, width, height);
  ft_render_img(mlx, win, &collectible, "./open.xpm", x, y);
}

void ft_render_exit(void *mlx, void *win, int width, int height, int x, int y) {
  s_img exit;
  ft_init_img(mlx, &exit, width, height);
  ft_render_img(mlx, win, &exit, "./images/sign_exit.xpm", x, y);
}
void ft_render_player(void *mlx, void *win, int width, int height, int x,
                      int y) {
  s_img player;
  ft_init_img(mlx, &player, width, height);
  ft_render_img(mlx, win, &player, "./images/player.xpm", x, y);
}
