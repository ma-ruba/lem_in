#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_data	str;
	char	*line;

	line = NULL;
	room_nb = 0;
	void reading_data(&str, line);
	if (checking_data())
	{
		algorithm();
	}
	void free_data();
}