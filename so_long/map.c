#include "./get_next_line/get_next_line.h"
#include "get_next_line/get_next_line_bonus.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void ft_render_empty_space(void *mlx, void *win, int width, int height, int x,
                           int y);
void ft_render_exit(void *mlx, void *win, int width, int height, int x, int y);
void ft_render_wall(void *mlx, void *win, int width, int height, int x, int y);
void ft_render_collectible(void *mlx, void *win, int width, int height, int x,
                           int y);
void ft_render_player(void *mlx, void *win, int width, int height, int x,
                      int y);

char **ft_parse_map(char *path, int *col, int *row) {
  int map_fd;
  int col_num;
  int row_num;
  char **parsed_map;
  char *line;
  int i;
  int j;

  map_fd = open(path, O_RDONLY);
  line = get_next_line(map_fd);
  col_num = 0;
  row_num = 0;
  while (line[col_num] && line[col_num] != '\n') {
    col_num++;
  }
  free(line);
  while (line) {
    row_num++;
    line = get_next_line(map_fd);
    free(line);
  }
  parsed_map = (char **)malloc(sizeof(char *) * row_num);
  i = 0;
  map_fd = open(path, O_RDONLY);
  while (i < row_num) {
    parsed_map[i] = (char *)malloc(sizeof(char) * row_num);
    j = 0;
    line = get_next_line(map_fd);
    while (j < row_num) {
      parsed_map[i][j] = line[j];
      j++;
    }
    free(line);
    i++;
  }
  *col = col_num;
  *row = row_num;
  return parsed_map;
}

void ft_render_map(void *mlx, void *win, s_map map) {
  int i;
  int j;
  int width;
  int height;
  int y;

  i = 0;
  y = 0;
  while (i < map.rows) {
    width = WIN1_SX / map.cols;
    height = WIN1_SY / map.rows;
    j = 0;
    while (j < map.cols) {
      if (map.map[i][j] == '0')
        ft_render_empty_space(mlx, win, width, width, width * j, y);
      else if (map.map[i][j] == '1')
        ft_render_wall(mlx, win, width, width, width * j, y);
      else if (map.map[i][j] == 'C')
        ft_render_collectible(mlx, win, width, width, width * j, y);
      else if (map.map[i][j] == 'E')
        ft_render_exit(mlx, win, width, width, width * j, y);
      else if (map.map[i][j] == 'P')
        ft_render_player(mlx, win, width, width, width * j, y);
      j++;
    }
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
