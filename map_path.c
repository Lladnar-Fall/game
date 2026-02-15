#include "so_long.h"

char **copy_map(t_game *game)
{
    char **copy_map;
    int row;

    copy_map = malloc(sizeof(char *) * (game->map_height + 1));
    if (!copy_map)
        return (0);
    row = 0;
    while (row < game->map_height)
    {
        copy_map[row] = ft_strdup(game->map[row]);
        if (!copy_map[row])
        {
            row = row - 1;
            while (row >= 0)
                free(copy_map[row--]);
            free(copy_map);
            return (0);
        }
        row++;
    }
    copy_map[row] = NULL;
    return (copy_map);
}

void flood_fill(t_game *game, char **map, int y, int x)
{
    if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width)
        return;
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    map[y][x] = 'V';
    flood_fill(game, map, y - 1, x);
    flood_fill(game, map, y + 1, x);
    flood_fill(game, map, y, x - 1);
    flood_fill(game, map, y, x + 1);
}

int check_valid_path(t_game *game)
{
    char **dup_map;
    int player_x;
    int player_y;
    int x;
    int y;

    dup_map = copy_map(game);
    if (!dup_map)
        return (0);

    player_x = -1;
    player_y = -1;
    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (dup_map[y][x] == 'P')
            {
                game->player_y = y;
                game->player_x = x;
                player_y = y;
                player_x = x;
            }
            x++;
        }
        y++;
    }
    if (player_x == -1 || player_y == -1)
    {
        free_map(dup_map);
        return (0);
    }

    flood_fill(game, dup_map, player_y, player_x);

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (dup_map[y][x] == 'E' || dup_map[y][x] == 'C')
            {
                free_map(dup_map);
                return (0);
            }
            x++;
        }
        y++;
    }
    free_map(dup_map);
    return (1);
}
