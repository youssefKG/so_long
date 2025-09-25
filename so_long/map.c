#include "./get_next_line/get_next_line.h"
#include "get_next_line/get_next_line_bonus.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

char **ft_parse_map(char *path, int *col, int *row) {
  int map_fd;
  int col_num;
  int row_num;
  char **parsed_map;
  char *line;
  char *tem;
  int i;
  int j;

  map_fd = open(path, O_RDONLY);
  line = get_next_line(map_fd);
  col_num = 0;
  row_num = 0;
  while (line[col_num] && line[col_num] != '\n') {
    col_num++;
  }
  while (line) {
    row_num++;
    line = get_next_line(map_fd);
  }
  free(line);

  parsed_map = (char **)malloc(sizeof(char *) * row_num);
  i = 0;
  map_fd = open(path, O_RDONLY);
  while (i < row_num) {
    parsed_map[i] = (char *)malloc(sizeof(char) * col_num);
    j = 0;
    line = get_next_line(map_fd);
    while (j < col_num) {
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

void ft_init_player(s_player *player, s_map map) {
  int i;
  int j;

  i = 0;
  while (i < map.cols) {
    j = 0;
    while (j < map.rows) {
      if (map.map[i][j] == 'P') {
        player->y = i;
        player->x = j;
        return;
      }
      j++;
    }
    i++;
  }
}
