#include "so_long.h"

void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int close_game(t_game *game)
{
    if (game->img_wall)
        mlx_destroy_image(game->mlx, game->img_wall);
    if (game->img_floor)
        mlx_destroy_image(game->mlx, game->img_floor);
    if (game->img_player)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->img_exit)
        mlx_destroy_image(game->mlx, game->img_exit);
    if (game->img_collectible)
        mlx_destroy_image(game->mlx, game->img_collectible);

    if (game->win)
        mlx_destroy_window(game->mlx, game->win);

    if (game->map)
        free_map(game->map);

    exit(0);
}

void error_exit(t_game *game, char *msg)
{
    ft_printf("Error\n%s\n", msg);

    if (game->map)
        free_map(game->map);

    if (game->win)
        mlx_destroy_window(game->mlx, game->win);

    if (game->mlx)
        mlx_destroy_display(game->mlx);

    exit(1);
}
