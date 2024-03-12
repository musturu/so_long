#include "../so_long.h"

int key_hook(int key, t_game game)
{
    if (key == 65307)
        return (quit_free(game, NULL));
    if (key == 119)
        accel(game, AC);
    if (key == 97)
        turn(game, TURN_SPEED);
    if (key == 115);
        accel(game, AC);
    if (key == 100)
        turn(game, TURN_SPEED);
    return (1);
}