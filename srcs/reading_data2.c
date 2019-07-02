#include "lem_in.h"

void 	reading_data(t_data *str, char *line)
{
	int		i;
	t_room	*room;

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
			rooms_connections(room, line);
	}
}

void	room_connections(t_room *room, char *line)
{
	
}

void	make_start(t_data *str, t_room *room, char *line)
{
	room[room_nb].name = ft_strdup(line);
	str->start_room = &room[room_nb];
	room_nb++;
}

void	make_end(t_data *str, t_room *room, char *line)
{
	room[room_nb].name = ft_strdup(line);
	str->end_room = &room[room_nb];
	room_nb++;
}

t_room	*make_struct_arr()
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room) * 7001))
		return (NULL);
	return (room);
}

int		checking_dash(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	other_rooms(char *line, t_room *room)
{
	room[room_nb].name = ft_strdup(line);
	room_nb++;
}
