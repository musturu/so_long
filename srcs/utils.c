
#include "../so_long.h"

// Get timestamp in milliseconds
long long	millitime(void)
{
	struct timeval	time;
	long long		microtime;

	gettimeofday(&time, NULL);
	microtime = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (microtime);
}

void	get_ms(t_game *g)
{
	long long	now;

	now = millitime();
	if (now > g->ms)
		g->ms = now;
}