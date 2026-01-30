#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"

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

} t_game;



#endif