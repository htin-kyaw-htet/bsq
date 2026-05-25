#include "bsq.h"

int	get_min(int a, int b, int c)
{
	int	m;

	m = a;
	if (b < m)
		m = b;
	if (c < m)
		m = c;
	return (m);
}

void	set_best(t_square *best, int val, int r, int c)
{
	if (val > best->size)
	{
		best->size = val;
		best->x = c - val + 1;
		best->y = r - val + 1;
	}
}

int	calc_val(t_map *map, int **dp, int r, int c)
{
	if (map->grid[r][c] == map->obs)
		return (0);
	if (r == 0 || c == 0)
		return (1);
	return (1 + get_min(dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]));
}

void	free_dp(int **dp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

t_square	solve_bsq(t_map *map)
{
	t_square	best;
	int			**dp;
	int			r;
	int			c;

	best = (t_square){0, 0, 0};
	dp = malloc(sizeof(int *) * map->rows);
	r = -1;
	while (++r < map->rows)
	{
		dp[r] = malloc(sizeof(int) * map->cols);
		c = -1;
		while (++c < map->cols)
		{
			dp[r][c] = calc_val(map, dp, r, c);
			set_best(&best, dp[r][c], r, c);
		}
	}
	free_dp(dp, map->rows);
	return (best);
}
