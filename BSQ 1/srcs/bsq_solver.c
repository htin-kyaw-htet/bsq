#include "bsq.h"

/*
** get_min: Returns the smallest of three integers.
** This is the core logic for the Dynamic Programming square finding.
*/
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

/*
** set_best: Updates the 'best' square coordinates if a larger one is found.
*/
void	set_best(t_square *best, int val, int r, int c)
{
	if (val > best->size)
	{
		best->size = val;
		best->x = c - val + 1;
		best->y = r - val + 1;
	}
}

/*
** calc_val: Calculates the value for a cell in the DP table.
** If cell is an obstacle: value is 0.
** If cell is on the top or left edge: value is 1 (if not obstacle).
** Otherwise: value is 1 + min of neighbors (top, left, top-left).
*/
int	calc_val(t_map *map, int **dp, int r, int c)
{
	if (map->grid[r][c] == map->obs)
		return (0);
	if (r == 0 || c == 0)
		return (1);
	return (1 + get_min(dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]));
}

/*
** free_dp: Frees the temporary integer grid used for calculation.
*/
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

/*
** solve_bsq: Implements the Dynamic Programming algorithm.
** 1. Creates a 2D integer table (dp).
** 2. Iterates through the map to fill the table.
** 3. Each number in the table represents the size of the largest
**    square ending at that coordinate.
*/
t_square	solve_bsq(t_map *map)
{
	t_square	best;
	int			**dp;
	int			r;
	int			c;

	best = (t_square){0, 0, 0};
	dp = malloc(sizeof(int *) * map->rows);
	if (!dp)
		return (best);
	r = -1;
	while (++r < map->rows)
	{
		dp[r] = malloc(sizeof(int) * map->cols);
		if (!dp[r])
		{
			free_dp(dp, r);
			return (best);
		}
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
