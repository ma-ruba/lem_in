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
# define			BLOCKED 0
# define			DELETED -1
# define			OPENED 1
# define			NOT_GIVEN -1

int					room_nb;

typedef struct		s_room //ячейка массива структур комнат
{
	char			*name;
	t_list			*neigb;
	int				value;
	int				status;
}					t_room;

typedef struct		s_list // ячейка списка соседей
{
	t_room			*room;
	struct s_list	*next;
	int				status;
}					t_list;

typedef struct		s_path	
{
	t_room			*room;
	struct s_path	*next;
}					t_path;

typedef struct 		s_plist
{
	t_path			*path;
	struct s_plist	*next;
}					t_plist;

typedef struct		s_reading_data
{
    int				amount_of_ants;
    t_room			*start_room;
    t_room			*end_room;
}					t_data;

t_plist    			*algorithm(t_room *start, t_room *finish);
int					cutting_path(t_room *start, t_room *finish, t_plist *plist);
int					both_directions(t_plist *plist, t_room *start);
int					width_search(t_room *start, t_room *finish, t_path *path);
int					give_values(t_room *start, t_room *finish, int cur_val);

#endif
