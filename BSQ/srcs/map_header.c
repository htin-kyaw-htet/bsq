#include "bsq.h"

/*
** validate_header: Checks if the first line of the map file is valid.
** It extracts:
** - map->rows: Number of lines in the map.
** - map->empty: Character for empty cells.
** - map->obs: Character for obstacles.
** - map->full: Character to draw the square.
** Returns 1 if valid, 0 if invalid.
*/
int	validate_header(t_map *map, char *h)
{
	int	len;

	len = ft_strlen(h);
	if (len < 4)
		return (0);
	map->full = h[len - 1];
	map->obs = h[len - 2];
	map->empty = h[len - 3];
	map->rows = ft_atoi_len(h, len - 3);
	if (map->rows <= 0)
		return (0);
	if (map->empty == map->obs || map->empty == map->full)
		return (0);
	if (map->obs == map->full)
		return (0);
	return (1);
}

/*
** read_header: Reads only the first line of the file (until \n).
** This line contains the map information.
*/
char	*read_header(int fd)
{
	char	*line;
	char	c;
	int		i;

	line = malloc(1024);
	if (!line)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		line[i] = c;
		i++;
		if (i >= 1023)
			break ;
	}
	line[i] = '\0';
	return (line);
}
