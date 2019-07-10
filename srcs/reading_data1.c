#include "lem_in.h"

t_room		*reading_data(t_data *str, char *line) //можно переписать, чтобы быстрее работало. Как только 1 раз встретилось
//тире, дальше идут только связи комнат + чтение не с консоли а из файла!!!!!
{
	int		i;
	t_room	*room;
	int 	index;

	index = 0;
	room = make_struct_arr();
	get_next_line(0, &line);
	str->amount_of_ants = ft_atoi(line); // Сначала же муравьи
	/*if (line[0] == "#" && line[1] != '#')
		get_next_line(0, &line);*/
	while (get_next_line(0, &line))
	{
		i = -1;
		if (ft_strequ(line, "##start"))
		{
			get_next_line(0, &line);
			make_start(str, room, line)
		}
		else if (ft_strequ(line, "##end"))
		{
			get_next_line(0, &line);
			make_end(str, room, line);
		}
		else if (line[0] == "#" && line[1] != '#')
			get_next_line(0, &line);
		else if (checking_dash(line))
			rooms_connections(room, line);
		else
		{
			if (index == 0)
				sorting_rooms(room);
			other_rooms(line, room);
			index = 1;
		}
	}
	return (room);
}

void		room_connections(t_room *room, char *line) //посмотрела. Все ОК
{
	int		i;
	t_room	*r;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	r = find_room(line, room);
	r.neigb = make_neighb_list(room, &line[i + 1]);
}

void		make_start(t_data *str, t_room *room, char *line) //посмотрела. Все ОК
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	room[room_nb].name = ft_strdup(line); //память должна удаляться!!!!!!!!!!
	room[room.nb].value = NOT_GIVEN;
	room[room.nb].status = OPENED;
	str->start_room = &room[room_nb];
	room_nb++;
}

void		make_end(t_data *str, t_room *room, char *line) //посмотрела. Все ОК
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	room[room_nb].name = ft_strdup(line); //память должна удаляться!!!!!!!!!!
	room[room.nb].value = NOT_GIVEN;
	room[room.nb].status = OPENED;
	str->end_room = &room[room_nb];
	room_nb++;
}

t_room		*make_struct_arr() // норма Посмотрела. Все ОК
{
	t_room	*room;
	
	if (!(room = (t_room*)malloc(sizeof(t_room) * MAXV)))
		return (NULL);
	return (room);
}

t_nlist    *make_neighb_list(t_room *rooms, char *line) // норма Посмотрела. Все ОК
{
    t_nlist *new;
	t_nlist *temp;

    new = (t_nlist*)malloc(sizeof(t_nlist));
	temp = rooms->neighb;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->room = find_room(line, rooms);
	new->next = NULL;
}
