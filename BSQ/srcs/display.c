#include "bsq.h"

/*
** print_cell: Determines if a cell should be printed as the map content
** or as the 'full' character (if it's part of the biggest square).
*/
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

/*
** display_result: Iterates through the grid and prints each row.
*/
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

/*
** display_error: Prints the standard "map error" message as required.
*/
void	display_error(void)
{
	write(1, "map error\n", 10);
}
