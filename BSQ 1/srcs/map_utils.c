#include "bsq.h"

/*
** free_map: Cleans up all memory used by the t_map structure.
** Important to call this to avoid memory leaks.
*/
void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}

/*
** get_first_row: Reads the very first line of the actual map grid.
** It determines the number of columns (width) based on this first row.
*/
int	get_first_row(int fd, t_map *map)
{
	char	c;
	char	buf[16384];
	int		j;

	j = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (j >= 16383 || (c != map->empty && c != map->obs))
			return (0);
		buf[j++] = c;
	}
	if (j == 0)
		return (0);
	map->cols = j;
	map->grid[0] = malloc(j + 1);
	if (!map->grid[0])
		return (0);
	j = -1;
	while (++j < map->cols)
		map->grid[0][j] = buf[j];
	map->grid[0][j] = '\0';
	return (1);
}

/*
** read_row: Reads a single row of the map and validates its characters.
** Checks that length matches map->cols and characters are valid.
*/
int	read_row(int fd, t_map *map, int r)
{
	char	c;
	int		j;

	j = 0;
	map->grid[r] = malloc(map->cols + 1);
	if (!map->grid[r])
		return (0);
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (j >= map->cols || (c != map->empty && c != map->obs))
			return (0);
		map->grid[r][j++] = c;
	}
	if (j != map->cols)
		return (0);
	map->grid[r][j] = '\0';
	return (1);
}

/*
** read_rows: Loops through the remaining rows to read the full map.
*/
int	read_rows(int fd, t_map *map)
{
	int	i;

	i = 1;
	while (i < map->rows)
	{
		if (!read_row(fd, map, i))
			return (0);
		i++;
	}
	return (1);
}
