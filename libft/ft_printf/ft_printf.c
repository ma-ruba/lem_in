/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:00:53 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:00:56 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*find_all_specifier(char *sp, t_specs *specs, va_list *ap)
{
	while (*sp != 'd' && *sp != 'i' && *sp != 'o' && *sp != 'u' && *sp != 'x'
		&& *sp != 'X' && *sp != 'c' && *sp != 's' && *sp != 'p' && *sp != '%'
		&& *sp != 'n' && *sp != 'D' && *sp != 'O' && *sp != 'U' && *sp != 'f'
		&& *sp != 'F' && *sp != 'e' && *sp != 'E' && *sp != 'a' && *sp != 'A'
		&& *sp != 'b' && *sp != 'g' && *sp != 'G')
	{
		if (*sp == '#' || *sp == '0' || *sp == '-' || *sp == '+' || *sp == ' ')
			sp = find_flag_specifier(sp, specs);
		else if ((*sp > '0' && *sp <= '9') || *sp == '*')
			sp = find_widht_specifier(sp, specs, ap);
		else if (*sp == '.')
			sp = find_precision_specifier(++sp, specs, ap);
		else if (*sp == 'l' || *sp == 'h' || *sp == 'L'
			|| *sp == 'j' || *sp == 'z' || *sp == 't')
			sp = find_size_specifier(sp, specs);
		else
		{
			find_type_specifier(sp, specs);
			return (--sp);
		}
	}
	sp = find_type_specifier(sp, specs);
	return (sp);
}

void	find_start_specifier(char *format, va_list *ap)
{
	t_specs	*specs;

	while (*format)
	{
		if (*format == '%')
		{
			specs = create_new_specs();
			format = find_all_specifier(format + 1, specs, ap);
			if (specs->type)
				format = get_value(format, specs, ap);
			free(specs);
		}
		else
		{
			ft_putchar(*format);
			g_len++;
		}
		format++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	g_len = 0;
	va_start(ap, format);
	find_start_specifier((char *)format, &ap);
	va_end(ap);
	return (g_len);
}
