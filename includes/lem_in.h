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

typedef struct		s_room //ячейка массива структур комнат
{
	char			*name;
	struct s_room	*neigb;
	int				status;
}					t_room;

typedef struct		s_list // ячейка списка соседей
{
	t_room			*room;
	struct s_list	*next;		
}					t_list;

typedef struct	s_reading_data
{
    int				amount_of_ants;
    t_room			*start_room;
    t_room			*end_room;
}					t_data;

void			make_neigb_list(t_room *room, t_room *rooms, char *line);

#endif
