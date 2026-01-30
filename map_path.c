#include "so_long.h"

int check_vald_path(t_game *game)
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
    //[2] Find player position
    //[3] Flood fill from player position
    //[4] Scan the map for unreachable C and E
    //[5] Free the map
    //[6] Return the result
}
