/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:25:07 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/29 15:06:03 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define 			MAXV 7000   /*максимальное количество вершин */
# define			OPENED 1
# define			CLOSED 0
# define			

int					room_nb;

typedef struct		s_room
{
	char			*name;
	struct s_room	*neigb;
	int				status;
}					t_room;

typedef struct	s_reading_data
{
    int				amount_of_ants;
    t_room			*start_room;
    t_room			*end_room;
}					t_data;

/*структура для создания списка путей*/
typedef struct 
{
	char *y; /* элемент  */
	struct path *next; /* следующий элемент в списке */
} path;

/* структура для графа*/
typedef struct 
{
	path *ways[MAXV + 1]; /* информация о смежности ????? */
	int nvertices;  /* количество вершин в графе */
	int nedges; /* количество ребер в графе */
}   graph;

void	reading_data(t_data *str, char *line);
t_room	*make_struct_arr();
int		checking_dash(char *line);
void	checking_data(t_data *str)

#endif
