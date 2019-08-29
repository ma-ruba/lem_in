#include "lem_in.h"

static void set_neighb(t_room *room)//норма
{
	int		i;

	i = -1;
	while (++i < MAXV)
		room[i].neighb = NULL;
}

void		read_start(char *line, int fd, t_data *str, t_room *room)
{
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	if ((line[0] == '#' && line[1] == '#') || (line[0] == '#' && line[1] != '#'))
	{
		free(line);
		get_next_line(fd, &line);
	}
	check_room(&line);
	printf("%s\n", line);
	make_start(str, room, line);
	idx_for_start = 1;
	//free(line);
}

void		read_end(char *line, int fd, t_data *str, t_room *room)
{
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	//if ((line[0] == '#' && line[1] != '#'))
	if (line)
	{
		if ((line[0] == '#' && line[1] == '#') || (line[0] == '#' && line[1] != '#'))// ?????????????????
		{
			free(line);
			get_next_line(fd, &line);
		}
	}
	check_room(&line);
	printf("%s\n", line);
	make_end(str, room, line);
	idx_for_end = 1;
	//free(line);
}

t_room		*reading_data(t_data *str, char *line, int fd)//норма
{
	t_room	*room;
	int 	index;

	index = 0;
	room = make_struct_arr();
	if (!check_ants(fd, &line))
		map_error();
	str->amount_of_ants = ft_atoi(line);
    free(line);                    /// valgrind
    line = NULL;
	index1 = str->amount_of_ants;
	index3 = str->amount_of_ants - 1;
	while (get_next_line(fd, &line))
		check(line, fd, str, room, &index);
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
	index_for_rc = 1;
}

void		make_start(t_data *str, t_room *room, char *line) //норма
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	room[room_nb].name = ft_strdup(line);
	str->start = NULL;
	str->start = ft_strdup(line);
	room[room_nb].value = NOT_GIVEN;
	room[room_nb].neighb = NULL;
	room[room_nb].status = OPENED;
	room[room_nb].is_ant_inside = 0;
	str->start_room = &room[room_nb];
	free(line);
	line = NULL;
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
	str->end = NULL;
	str->end = ft_strdup(line);
	room[room_nb].value = NOT_GIVEN;
	room[room_nb].status = OPENED;
	room[room_nb].neighb = NULL;
	room[room_nb].is_ant_inside = 3;
	str->end_room = &room[room_nb];
    free(line);
    line = NULL;
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
