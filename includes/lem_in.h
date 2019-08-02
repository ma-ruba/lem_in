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
# include <stdio.h> // НЕ ЗАБЫТЬ ВСТАВИТЬ СВОЙ PRINTF!!!!!!!!!!!!!!!!!!!!!!!

# define 			MAXV 7000   /*максимальное количество вершин */
# define			BLOCKED 0
# define			DELETED -1
# define			OPENED 1
# define			NOT_GIVEN -1
# define			PRINTED 1
# define			NOT_PRINTED -1
# define			END 3

int					room_nb;
int					n_ant;
int					index1;
int					index2;
int					index3;
int					i;

typedef struct		s_room //ячейка массива структур комнат
{
	char			*name;
	struct s_nlist	*neighb;
	int				value;
	int				status;
	int				is_ant_inside;
}					t_room;

typedef struct		s_nlist // ячейка списка соседей
{
	t_room			*room;
	struct s_nlist	*next;
	int				status;
}					t_nlist;

typedef struct		s_path	
{
	t_room			*room;
	struct s_path	*next;
	int				print_index;
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
	char			*start;
	char			*end;
	int				ants_in_the_end_room;
	int				*delta;
	int				l;
	int				number_of_pathes;
}					t_data;

typedef struct		s_array
{
	int				num_of_steps;
	int				num_of_pathes;
}					t_array;

t_plist    			*algorithm(t_room *start, t_room *finish, t_room *arr);
int					cutting_path(t_room *start, t_room *finish, t_plist *plist, int *index);
int					both_directions(t_plist *plist, t_room *start);
int					width_search(t_room *start, t_room *finish, t_path **path);
int					give_values(t_room **start, t_room *finish, int cur_val);

t_plist				*make_path_list(t_plist *prev, t_path *current);
t_path				*make_path(t_path *prev, t_room *current, int index);
int					check_finish(t_room *finish, t_room *current);
void				clean_values(t_room *arr);
t_room				**make_queue();

void				free_pathlist(t_path *path, t_plist *plist);
void				free_path(t_plist *plist);
void				free_neighb_list(t_room *room, t_data *str);

void				block_direction(t_plist *plist, t_room *start);
void				unblock_direction(t_plist *plist, t_room *start);
void				unblock_start(t_room *start);
void				find_room2(t_path *path, t_room *room);
int					find_room3(t_path *path, t_room *room);
void				unblock_rooms(t_plist *plist);

int 				checking_data(t_data *str);
int     			check_room(char **line);
int     			check_ants(const int fd, char **line);
void     			check(char *line, int fd, t_data *str, t_room *room, int *index);

t_room				*reading_data(t_data *str, char *line, int fd);
void				read_start(char *line, int fd, t_data *str, t_room *room);
void				read_end(char *line, int fd, t_data *str, t_room *room);
void				room_connections(t_room *room, char *line);
void				make_start(t_data *str, t_room *room, char *line);
void				make_end(t_data *str, t_room *room, char *line);
t_room				*make_struct_arr();
void    			make_neighb_list(t_room *rooms, char *line, t_room *room);

t_array				*creating_of_array();
int 				number_of_pathes(t_data *read, t_plist *pointers, t_array *pathes);
void				comparing_of_values(t_array *pathes, int number_of_steps, int num_p);

void				sorting_rooms(t_room *room, int low, int high, t_data *str);
t_room				*find_room(char *buff, t_room *room);
int					checking_dash(char *line);
void				other_rooms(char *line, t_room *room);

void 				ants_going_through_graph(t_plist *pointers, int num_of_pathes, t_data *read);
void				moving_ants(int *array_num_ant, t_data *read, int *value_of_ants, t_plist *plist);
void				ants_inside(t_plist *pointers, int i, t_data *read);

void				print_room(t_plist *tmp, int *ant_val, t_data *read, int *array_num_ant);
void				ants_printing(t_plist *plist, int *value_of_ants, int *array_num_ant, t_data *read);

void    			malloc_error();
void    			map_error();

#endif
