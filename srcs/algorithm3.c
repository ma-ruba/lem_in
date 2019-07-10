#include "lem_in.h"

void	creating_of_array(t_array *pathes)
{
	pathes = (t_array*)malloc(sizeof(t_array) * 2);
	pathes->num_of_steps = 0;
	pathes->num_of_pathes = 0;
}

int number_of_pathes(int *num_of_pathes, t_data *read, t_plist *pointers, t_array *pathes)
{
	int number_of_steps;
	int sum_p; // длина всех путей
	int num_p; // количество всех путей
	t_plist *tmp;
	t_array *tmp2;
	
	tmp = pointers; // указатель для того, чтобы выяснить, сколько путей
	while (tmp)
	{
		tmp2 = tmp->path;
		while (tmp2)
		{
			tmp2 = tmp2->next;
			sum_p += 1;
		}
		number_of_steps = (read->amount_of_ants + sum_p - 1) / num_p;
		tmp = tmp->next;
		num_p += 1;
		comparing_of_values(pathes, number_of_steps, num_p);
	}
	if (pathes[0]->num_of_pathes != 0)
		return (pathes[0]->num_of_pathes);
	else
		return (pathes[1]->num_of_pathes);
}

void	comparing_of_values(t_array *pathes, int number_of_steps, int num_p)
{
	if (pathes[0]->num_of_pathes == 0 && pathes[1]->num_of_pathes == 0)
	{
		pathes[0]->num_of_pathes = num_p;
		pathes[0]->num_of_steps = number_of_steps;
		return ;
	}
	else if (pathes[0]->num_of_pathes != 0 && pathes[1]->num_of_pathes == 0)
	{
		pathes[1]->num_of_pathes = num_p;
		pathes[1]->num_of_steps = number_of_steps;
	}
	else if (pathes[0]->num_of_pathes == 0 && pathes[1]->num_of_pathes != 0)
	{
		pathes[0]->num_of_pathes[0] = num_p;
		pathes[0]->num_of_steps = number_of_steps;
	}
	if (pathes[0]->num_of_pathes > pathes[1]->num_of_pathes)
	{
		pathes[0]->num_of_pathes = 0;
		pathes[0]->num_of_steps = 0;
	}
	else
	{
		pathes[1]->num_of_pathes = 0;
		pathes[1]->num_of_steps = 0;
	}
}
