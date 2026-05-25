/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkyaw <htkyaw@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:14:27 by htkyaw            #+#    #+#             */
/*   Updated: 2026/05/25 18:30:08 by htkyaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obs;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

/* utils.c */
void		ft_putchar(char c);
int			ft_strlen(char *str);
int			ft_atoi_len(char *str, int len);

/* map_header.c */
int			validate_header(t_map *map, char *header);
char		*read_header(int fd);

/* map_parsing.c */
t_map		*parse_map(int fd);

/* map_utils.c */
void		free_map(t_map *map);
int			get_first_row(int fd, t_map *map);
int			read_rows(int fd, t_map *map);

/* bsq_solver.c */
t_square	solve_bsq(t_map *map);

/* display.c */
void		display_result(t_map *map, t_square sq);
void		display_error(void);

#endif
