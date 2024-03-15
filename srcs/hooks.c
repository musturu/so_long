#include "../so_long.h"

int key_hook(int key, t_game game)
{
    if (key == 65307)
        return (quit_free(game, NULL));
    if (key == 119)
        accel(game, AC);
    if (key == 97)
        turn(game, TURN_SPEED);
    if (key == 115)
        accel(game, DC);
    if (key == 100)
        turn(game, TURN_SPEED);
    return (1);
}

void    update(t_game g)
{
    long long milli;
    long long diff;

    milli = millitimestamp();
    diff = milli - g.ms;
    if (diff > 15)
    {
        
    }
}
