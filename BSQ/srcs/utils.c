#include "bsq.h"

/*
** ft_putchar: Simple helper to write a single character to standard output.
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** ft_strlen: Calculates the length of a string.
** Used for parsing the map header and strings.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** ft_atoi_len: Converts a string segment into an integer.
** Specifically used to extract the number of lines from the map header.
** Returns -1 if it finds a non-digit character.
*/
int	ft_atoi_len(char *str, int len)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
