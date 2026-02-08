#include "so_long.h"

int count_lines(char *file)
{
    char *line;
    int fd;
    int count;

    fd = read(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    count = 0;
    line = get_next_line(fd);
    while (line)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (count);
}

void fill_map(t_game *game, int fd)
{
    int i;
    char *line;

    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        game->map[i] = line;
        i++;
        line = get_next_line(fd);
    }
    game->map[i] = NULL;
}

void    read_map(t_game *game, char *filename)
{
    int fd;

    game->map_height = count_lines(filename);
    if (game->map_height <= 0)
        error_exit("Invalid map");

    game->map = malloc(sizeof(char *) * (map_height + 1));
    if (!game->map)
        error_exit("Malloc failed");

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Error opening map");

    fill_map(game, fd);

    close(fd);
    game->map_width = ft_strlen(game->map[0]) - 1;
}
