#include "bsq.h"

/*
** process_file: This function handles a single map file.
** 1. It opens the file (or uses stdin if filename is NULL).
** 2. It calls parse_map to read and validate the map content.
** 3. If valid, it calls solve_bsq to find the square and display_result to print it.
** 4. Finally, it cleans up memory and closes the file.
*/
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

/*
** main: The entry point of the program.
** - If no arguments are given, it reads from standard input (argc == 1).
** - If arguments are given, it processes each file one by one.
** - It prints a newline between solutions as required by the subject.
*/
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
