#include "bsq.h"

void	process_file(char *filename)
{
	int			fd;
	t_map		*map;
	t_square	sq;

	if (filename)
		fd = open(filename, O_RDONLY);
	else
		fd = 0;
	if (fd < 0)
	{
		display_error();
		return ;
	}
	map = parse_map(fd);
	if (!map)
		display_error();
	else
	{
		sq = solve_bsq(map);
		display_result(map, sq);
		free_map(map);
	}
	if (filename)
		close(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		process_file(NULL);
	else
	{
		i = 1;
		while (i < argc)
		{
			process_file(argv[i]);
			if (i < argc - 1)
				ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
