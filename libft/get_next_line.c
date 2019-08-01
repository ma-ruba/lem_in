/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:27:37 by bconwy            #+#    #+#             */
/*   Updated: 2019/01/31 16:27:58 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_n(char **stack, char **line)
{
	char		*tmp;

	if ((tmp = ft_strchr(*stack, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strdup(*stack)))
		{
			free(*stack);
			return (-1);
		}
		tmp++;
		if (!(tmp = ft_strdup((const char *)tmp)))
			return (-1);
		free(*stack);
		*stack = tmp;
		return (1);
	}
	return (0);
}

static int	ft_read_line(char **line, char *buff, char **stack)
{
	char		*tmp;

	if (*stack)
	{
		tmp = ft_strjoin((const char *)*stack, buff);
		free(*stack);
		*stack = tmp;
	}
	else
		*stack = ft_strdup((const char *)buff);
	if ((tmp = ft_strchr((const char *)*stack, '\n')))
	{
		*tmp = '\0';
		free(buff);
		if (!(*line = ft_strdup((const char *)*stack)))
		{
			free(*stack);
			return (-1);
		}
		tmp = ft_strdup((const char *)++tmp);
		free(*stack);
		*stack = tmp;
		return (1);
	}
	return (0);
}

static void	ft_exception(int *ret, char **stack, char **line)
{
	if (*ret == 0 && *stack != NULL && *stack[0] != '\0')
	{
		*line = *stack;
		*stack = NULL;
		*ret = 1;
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*stack[MAX_FD];
	char		*buff;
	int			ret;

	if ((fd < 0 || fd >= MAX_FD) || !line ||
		!(buff = ft_strnew(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (stack[fd])
	{
		if ((ret = ft_check_n(&stack[fd], line)))
			return (ret);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((ret = ft_read_line(line, buff, &stack[fd])))
			return (ret);
	}
	ft_exception(&ret, &stack[fd], line);
	if (ret == 0 && *line)
		*line = NULL;
	free(buff);
	return (ret);
}
