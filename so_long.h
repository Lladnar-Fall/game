#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>

typedef struct s_game
{
    char **map;
    int map_width;
    int map_height;
    int player_y;
    int player_x;
    int remaining;
    int moves;
    void *mlx;
    void *win;
    void *img_floor;
    void *img_wall;
    void *img_player;
    void *img_collectible;
    void *img_exit;

} t_game;


void	free_map(char **map);
void 	lood_fill(t_game *game, char **map, int y, int x);
int		check_vald_path(t_game *game);
void	close_game(t_game *game);

#endif