#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# include "mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

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

int		check_map(t_game *game);
char	**copy_map(t_game *game);
void	flood_fill(t_game *game, char **map, int y, int x);
int		check_valid_path(t_game *game);
int		count_lines(char *file);
void	fill_map(t_game *game, int fd);
void	read_map(t_game *game, char *filename);
int		handle_keypress(int key_code, t_game *game);
void	update_player_and_map(t_game *game, int y, int x);
int		try_move(t_game *game, int dy, int dx);
void	render_tile(t_game *game, int y, int x);
void	render_map(t_game *game);

void	free_map(char **map);
void	error_exit(t_game *game, char *msg);
int		close_game(t_game *game);

#endif