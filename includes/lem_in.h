/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:25:07 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:41:43 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAXV 20000
# define BLOCKED 0
# define DELETED -1
# define OPENED 1
# define NOT_GIVEN -1
# define PRINTED 1
# define NOT_PRINTED -1
# define END 3

int					g_room_nb;
int					g_n_ant;
int					g_index1;
int					g_index2;
int					g_index3;
int					g_i;
int					g_index_for_rc;
int					g_idx_for_start;
int					g_idx_for_end;

typedef struct		s_room
{
	char			*name;
	struct s_nlist	*neighb;
	int				value;
	int				status;
	int				is_ant_inside;
}					t_room;

typedef struct		s_nlist
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

typedef struct		s_plist
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

typedef struct		s_norm
{
	int				i;
	int				j;
	int				block;
}					t_norm;

typedef struct		s_array
{
	int				num_of_steps;
	int				num_of_pathes;
}					t_array;

t_plist				*algorithm(t_room *start, t_room *finish, t_room *arr);
int					cutting_path(t_room *start, t_room *finish, t_plist *plist,
							int *index);
int					cutting_path2(t_room *start, t_room *finish,
							t_plist *first);
int					both_directions(t_plist *plist, t_room *start);
int					width_search(t_room *start, t_room *finish, t_path **path,
							int index);
int					give_values(t_room **start, t_room *finish, int cur_val);
t_room				**give_values3(t_norm *norm, t_room **start);
void				give_values2(t_norm *norm, t_room **queue, t_nlist **tmp,
							int *cur_val);
int					give_values4(t_room **queue);
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
int					checking_data(t_data *str, t_room *room);
int					check_room(char **line, t_room *room, t_data *str);
void				check_room2(char **line, t_room *room, t_data *str);
void				check_room3(char **line, t_room *room, t_data *str,
							int count);
int					check_ants(char **line);
void				check(char *line, t_data *str, t_room *room,
							int *index);
void				check2(char *line, t_data *str, t_room *room);
void				checking_duplicates(t_room *room, char *room_name,
							t_data *str);
t_room				*reading_data(t_data *str, char *line);
void				read_start(char *line, t_data *str, t_room *room);
void				read_end(char *line, t_data *str, t_room *room);
void				room_connections(t_room *room, char *line, t_data *str);
void				make_start(t_data *str, t_room *room, char *line);
void				make_end(t_data *str, t_room *room, char *line);
t_room				*make_struct_arr();
void				make_neighb_list(t_room *rooms, char *line, t_room *room,
							t_data *str);
t_array				*creating_of_array();
int					number_of_pathes(t_data *read, t_plist *pointers,
							t_array *pathes);
void				comparing_of_values(t_array *pathes, int number_of_steps,
							int num_p);
void				comparing_of_values2(t_array *pathes);
void				sorting_rooms(t_room *room, int low, int high, t_data *str);
t_room				*find_room(char *buff, t_room *room, t_data *str);
int					checking_dash(char *line);
void				other_rooms(char *line, t_room *room, t_data *str);
void				ants_going_through_graph(t_plist *pointers,
							int num_of_pathes, t_data *read);
void				moving_ants(int *array_num_ant, t_data *read,
							int *value_of_ants, t_plist *plist);
void				ants_inside(t_plist *pointers, int i, t_data *read);
void				print_room(t_plist *tmp, int *ant_val, t_data *read,
							int *array_num_ant);
void				ants_printing(t_plist *plist, int *value_of_ants,
							int *array_num_ant, t_data *read);
void				print_for_start_end(t_data *str, t_room *room);
void				malloc_error();
void				map_error(t_room *room, t_data *str);
void				free_array_num_ant(int *array_num_ant);
void				smth_for_main(void);

#endif
