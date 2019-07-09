#include "lem_in.h"

int			main(int argc, char **argv) //норма
{
	t_data	str;
	char	*line;
	t_plist	*path_list;
	t_room	*room;

	line = NULL;
	room_nb = 0;
	index = 0;
	room = reading_data(&str, line);
	if (checking_data(&str))
	{
		path_list = algorithm(str.start_room, str.finish_room, room);
	}
	free_neighb_list(room);
}