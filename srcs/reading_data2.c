#include "lem_in.h"

static int	partition(t_room *room, int low, int high)
{
	t_nlist pivot;
	int i;
	int j;

	i = (low - 1);
	pivot = room[high];
	j = low;
	while (j <= high - 1)
	{
		if (ft_strcmp(room[j]->name, room[pivot]->name) <= 0) //???
		{
			i++;
			ft_uniswap(&room[i], &room[j], sizeof(t_room));
		}
		j++;
	}
	ft_uniswap(&room[i + 1], &room[high], sizeof(t_room));
	return (i + 1);
}

void sorting_rooms(t_room *room)
{
	int low;
	int high;
	int pi;

	low = 0;
	high = room_nb - 1;
	if (low < high)
	{
		pi = partition(room, low, high);
		quick_sort(room, low, pi - 1);
		quick_sort(room, pi + 1, high);
	}
}

t_room	*find_room(char *buff, t_room *room) //Посмотрела. Все ОК!
{
	int start;
	int end;
	int middle;
	int	res;

	start = 0;
	end = room_nb;
	while (start <= end)
	{
		middle = (start + end) / 2;
		res = ft_strcmp(room[middle]->name, buff);
		if (res > 0)
			end = middle - 1;
		else if (res < 0)
			start = middle + 1;
		else
			return (room[middle]->name);
	}
}

int		checking_dash(char *line) //Посмотрела. Все ОК!
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

void	other_rooms(char *line, t_room *room) //Посмотрела. Все ОК!
{
	int	i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	room[room_nb].name = ft_strdup(line);
	room[room.nb].value = NOT_GIVEN;
	room[room.nb].status = OPENED;
	room_nb++;
}
