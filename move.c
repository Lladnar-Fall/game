#include "so_long.h"

void    update_player_and_map(t_game *game, int y, int x)
{
    game->map[game->player_y][game->player_x] = '0';
    game->map[y][x] = 'P';
    game->player_y = y;
    game->player_x = x;
    game->moves++;
    ft_printf("Moves: %d\n", game->moves);
}

int try_move(t_game *game, int dy, int dx)
{
    int new_y;
    int new_x;

    new_y = game->player_y + dy;
    new_x = game->player_x + dx;

    if (new_y < 0 || new_y >= game->map_height ||
        new_x < 0 || new_x >= game->map_width)
        return (0);
    if (game->map[new_y][new_x] == '1')
        return (0);
    if (game->map[new_y][new_x] == 'C')
    {
        game->remaining--;
        game->map[new_y][new_x] = '0';
    }
    if (game->map[new_y][new_x] == 'E')
    {
        if (game->remaining > 0)
            return (0);
        close_game(game);
    }
    update_player_and_map(game, new_y, new_x);
    return (1);
}
