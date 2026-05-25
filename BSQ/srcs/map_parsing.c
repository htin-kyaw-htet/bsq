#include "bsq.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->rows = 0;
	map->cols = 0;
	return (map);
}

t_map	*parse_map(int fd)
{
	t_map	*map;
	char	*h;
	int		i;

	map = init_map();
	h = read_header(fd);
	if (!h || !validate_header(map, h))
	{
		free(h);
		free_map(map);
		return (NULL);
	}
	free(h);
	map->grid = malloc(sizeof(char *) * map->rows);
	i = -1;
	while (++i < map->rows)
		map->grid[i] = NULL;
	if (!get_first_row(fd, map) || !read_rows(fd, map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
