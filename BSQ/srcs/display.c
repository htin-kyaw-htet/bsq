#include "bsq.h"

void	print_cell(t_map *map, t_square sq, int r, int c)
{
	int	in_y;
	int	in_x;

	in_y = (r >= sq.y && r < sq.y + sq.size);
	in_x = (c >= sq.x && c < sq.x + sq.size);
	if (in_y && in_x)
		ft_putchar(map->full);
	else
		ft_putchar(map->grid[r][c]);
}

void	display_result(t_map *map, t_square sq)
{
	int	r;
	int	c;

	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->cols)
		{
			print_cell(map, sq, r, c);
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

void	display_error(void)
{
	write(1, "map error\n", 10);
}
