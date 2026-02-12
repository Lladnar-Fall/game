#include "so_long.h"


int check_map(t_game *game)
{
    int y;
    int x;
    int width;
    int p;
    int c;
    int e;

    p = 0;
    c = 0;
    e = 0;
    //[1] Check rectangular
    width = ft_strlen(game->map[0]);
    y = 0;
    while (y < game->map_height)
    {
        if ((int)ft_strlen(game->map[y]) != width)
            return (0);
        y++;
    }
    //[2] Check walls
    x = 0;
    while (x < game->map_width)
    {
        if (game->map[0][x] != '1' ||
            game->map[game->map_height - 1][x] != '1')
            return (0);
        x++;
    }
    y = 0;
    while (y < game->map_height)
    {
        if (game->map[y][0] != '1' ||
            game->map[y][game->map_width - 1] != '1')
            return (0);
        y++;
    }
    //[3] Check valid character + count elements
    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] != '0'
            && game->map[y][x] != '1'
            && game->map[y][x] != 'C'
            && game->map[y][x] != 'E'
            && game->map[y][x] != 'P')
            return (0);
        
            if (game->map[y][x] == 'P')
                p++;
            if (game->map[y][x] == 'C')
                c++;
            if (game->map[y][x] == 'E')
                e++;
            x++;
        }
        y++;
    }
    if (p != 1 || c < 1 || e != 1)
    return (0);

    game->remaining = c;
    //[4] Check required element count
    
    return (1);
}