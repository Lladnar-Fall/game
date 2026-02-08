#include "so_long.h"

int handle_keypress(int key_code, t_game *game)
{
    int dx;
    int dy;
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
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100