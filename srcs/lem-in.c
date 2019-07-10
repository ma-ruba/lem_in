#include "lem_in.h"

int			main(int argc, char **argv) //норма
{
	t_data	str;
	char	*line;
	t_plist	*path_list;
	t_room	*room;
	int		fd;

	line = NULL;
	room_nb = 0;
	index2 = 0;
	n_ant = 0;
	index3 = 0;
	if (fd = open(argv[0], O_RDONLY) == -1)
		exit (1);
	room = reading_data(&str, line, fd);
	if (checking_data(&str))
	{
		path_list = algorithm(str.start_room, str.finish_room, room);
	}
	free_neighb_list(room);
}