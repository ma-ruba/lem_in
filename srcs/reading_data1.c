#include "lem_in.h"

t_room		*reading_data(t_data *str, char *line)
{
	int		i;
	t_room	*room;
	int 	index;

	index = 0;
	room = make_struct_arr();
	get_next_line(0, &line);
	if (line[0] == "#" && line[1] != '#')
		get_next_line(0, &line);
	str->amount_of_ants = ft_atoi(line);
	while (get_next_line(0, &line))
	{
		i = -1;
		if (line[0] == "#" && line[1] != '#')
			get_next_line(0, &line);
		else if (ft_strequ(line, "##start"))
		{
			get_next_line(0, &line);
			make_start(str, room, line)
		}
		else if (ft_strequ(line, "##end"))
		{
			get_next_line(0, &line);
			make_end(str, room, line);
		}
		else if (checking_dash(line))
			other_rooms(line, room);
		else
		{
			if (index == 0)
				sorting_rooms(room);
			rooms_connections(room, line);
			index = 1;
		}
	}
	return (room);
}

void		room_connections(t_room *room, char *line)
{
	int		i;
	t_room	*r;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	r = find_room(ft_strdup(line), room);
	r.neigb = make_neighb_list(room, line);
}

void		make_start(t_data *str, t_room *room, char *line)
{
	room[room_nb].name = ft_strdup(line);
	room[room.nb].value = NOT_GIVEN;
	room[room.nb].status = OPENED;
	str->start_room = &room[room_nb];
	room_nb++;
}

void		make_end(t_data *str, t_room *room, char *line)
{
	room[room_nb].name = ft_strdup(line);
	str->end_room = &room[room_nb];
	room_nb++;
}

t_room		*make_struct_arr() // норма
{
	t_room	*room;
	int		i;

	i = 0;
	if (!(room = (t_room*)malloc(sizeof(t_room) * (MAXV + 1))))
		return (NULL);
	while (i != MAXV)
	{
		room[i] = NULL;
		i++;
	}
	return (room);
}
