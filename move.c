#include "so_long.h"


int handle_keypress(int key_code, t_game *game)
{
    int dx;
    int dy;

    ft_printf("Key pressed: %d\n", key_code);
    //[1] handle keypress
    if (key_code == 65307)
        close_game(game);
    //[2] Initialize dy and dx
    dy = 0;
    dx = 0;
    //[3] Map keycode to direction'
    if (key_code == 119)
        dy = -1;
    else if (key_code == 115)
        dy = 1;
    else if (key_code == 97)
        dx = -1;
    else if (key_code == 100)
        dx = 1;
    //[4] call try_move
    if (try_move(game, dy, dx))
        render_map(game);
    //[5] Redraw map if move succeeded
    return (0);
}

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

    if (dx == 0 && dy == 0)
        return (0);

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
