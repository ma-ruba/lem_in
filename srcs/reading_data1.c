#include "lem_in.h"

static void set_neighb(t_room *room)//норма
{
	int		i;

	i = -1;
	while (++i < MAXV)
		room[i].neighb = NULL;
}

t_room		*reading_data(t_data *str, char *line, int fd)//не норма +25 строк
{
	int		i;
	t_room	*room;
	int 	index;

	index = 0;
	room = make_struct_arr();
	get_next_line(fd, &line);
	str->amount_of_ants = ft_atoi(line); // Сначала же муравьи
	/*if (line[0] == "#" && line[1] != '#')
		get_next_line(0, &line);*/
	index1 = str->amount_of_ants;
	index3 = str->amount_of_ants - 1;
	while (get_next_line(fd, &line))
	{
		i = -1;
		if (ft_strequ(line, "##start"))
		{
			printf("%s\n", line);
			free(line);
			get_next_line(fd, &line);
			printf("%s\n", line);
			make_start(str, room, line);
		}
		else if (ft_strequ(line, "##end"))
		{
			printf("%s\n", line);
			free(line);
			get_next_line(fd, &line);
			printf("%s\n", line);
			make_end(str, room, line);
		}
		else if (line[0] == '#' && line[1] != '#')
		{
			printf("%s\n", line);
			free(line);
			continue ;
			//get_next_line(fd, &line);
		}
		else if (checking_dash(line))
		{
			printf("%s\n", line);
			if (index == 0)
				sorting_rooms(room, 0, room_nb - 1, str);
			index = 1;
			room_connections(room, line);
		}
		else
		{
			printf("%s\n", line);
			other_rooms(line, room);
		}
		free(line);
	}
	return (room);
}

void		room_connections(t_room *room, char *line) //норма
{
	int		i;
	t_room	*r;
	t_room	*r2;

	i = 0;
	while (line[i] != '-')
		i++;
	line[i] = '\0';
	r = find_room(line, room);
	make_neighb_list(room, &line[i + 1], r);
	r2 = find_room(&line[i + 1], room);
	make_neighb_list(room, &line[0], r2);
}

void		make_start(t_data *str, t_room *room, char *line) //норма
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	room[room_nb].name = ft_strdup(line);
	str->start = ft_strdup(line);;
	room[room_nb].value = NOT_GIVEN;
	room[room_nb].neighb = NULL;
	room[room_nb].status = OPENED;
	room[room_nb].is_ant_inside = 0;
	str->start_room = &room[room_nb];
	room_nb++;
}

void		make_end(t_data *str, t_room *room, char *line) //норма
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	if (!(room[room_nb].name = ft_strdup(line)))
		malloc_error();
	str->end = ft_strdup(line);
	room[room_nb].value = NOT_GIVEN;
	room[room_nb].status = OPENED;
	room[room_nb].neighb = NULL;
	room[room_nb].is_ant_inside = 3;
	str->end_room = &room[room_nb];
	room_nb++;
}

t_room		*make_struct_arr() // норма 
{
	t_room	*room;
	
	if (!(room = (t_room*)ft_memalloc(sizeof(t_room) * MAXV)))
		malloc_error();
	set_neighb(room);
	return (room);
}

void		make_neighb_list(t_room *rooms, char *line, t_room *room)//норма
{
    t_nlist *new;
	t_nlist *temp;

    if (!(new = (t_nlist*)ft_memalloc(sizeof(t_nlist))))
		malloc_error();
	temp = room->neighb;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->room = find_room(line, rooms);
		new->status = OPENED;
		new->next = NULL;
	}
	else
	{
		room->neighb = new;
		new->room = find_room(line, rooms);
		new->status = OPENED;
		new->next = NULL;
	}
}
