#include "so_long.h"

void render_tile(t_game *game, int y, int x)
{
    mlx_put_image_to_window(
        game->mlx,
        game->win,
        game->img_floor,
        x * TILE_SIZE,
        y * TILE_SIZE
    );

    if (game->map[y][x] == '0' || game->map[y][x] == 'P' || game->map[y][x] == 'C' || game->map[y][x] == 'E')
    mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);

    if (game->map[y][x] == '1')
        mlx_put_image_to_window(game->mlx, game->win,
        game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
    else if (game->map[y][x] == 'P')
        mlx_put_image_to_window(game->mlx, game->win,
        game->img_player, x * TILE_SIZE, y * TILE_SIZE);
    else if (game->map[y][x] == 'E')
        mlx_put_image_to_window(game->mlx, game->win,
        game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
}

void    render_map(t_game *game)
{
    int y;
    int x;
    //[1] Loop over game
    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            render_tile(game, y, x);
            x++;
        }
        y++;
    }
    //[2] loop over map coloumns
    //[3] Draw floor
    //[4] Draw wall/player/collectible/exit
}