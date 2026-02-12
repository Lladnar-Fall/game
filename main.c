#include "so_long.h"

// int main()
// {
//     void    *mlx_connection;
//     void    *mlx_window;

//     mlx_connection = mlx_init();
//     mlx_window = mlx_new_window(
//         mlx_connection,
//         500,
//         500,
//         "so_long"
//     );
//     mlx_loop(mlx_connection);
// }

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

void    load_images(t_game *game)
{
    int w;
    int h;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &w, &h);
    
}

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx,
                    game->map_width * TILE_SIZE,
                    game->map_height * TILE_SIZE,
                    "so_long");

    load_images(game);
}

int main(int ac, char **av)
{
    t_game game;

    ft_memset(&game, 0, sizeof(t_game));

    if (ac != 2)
        error_exit(&game, "Usage: ./so_long map.ber");

    read_map(&game, av[1]);
    int i = 0;
    while (game.map[i])
    {
        ft_printf("%s\n", game.map[i]);
        i++;
    }
    check_map(&game);
    check_valid_path(&game);

    init_game(&game);        // mlx + window + images
    render_map(&game);

    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);

    mlx_loop(game.mlx);
}