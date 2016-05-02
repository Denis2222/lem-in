/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:03 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 12:22:35 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

int		lineparser2(t_li *li, char *line)
{
	if (isant(line))
	{
		if (ft_atoi(line) > 0 &&
			ft_strlen(line) < 11 && ft_atoi(line) < INT_MAX)
		{
			if (li->ant == 0 && !li->rooms && !li->wires)
				li->ant = ft_atoi(line);
			return (1);
		}
	}
	else if (iswire(line))
		return (newwire(li, line));
	return (0);
}

int		lineparserflag(t_li *li, char *line, int *flag)
{
	if (ft_strequ(line, "##start"))
	{
		if (*flag == 2 || li->start)
		{
			if (li->opts['v'])
				ft_printf("{red}What the Flag ! [%s] {eoc}\n", line);
			return (0);
		}
		*flag = 1;
		return (2);
	}
	else if (ft_strequ(line, "##end"))
	{
		if (*flag == 1 || li->end)
		{
			if (li->opts['v'])
				ft_printf("{red}What the Flag ! [%s] {eoc}\n", line);
			return (0);
		}
		*flag = 2;
		return (3);
	}
	else if (ft_strncmp(line, "#", 1) == 0)
		return (4);
	return (1);
}

int		lineparser(t_li *li, char *line)
{
	static int	flag = 0;
	int			ret;

	if ((ret = lineparserflag(li, line, &flag)) != 1)
		return (ret);
	else if (isroom(line))
	{
		if (newroom(li, line, flag))
		{
			flag = 0;
			return (5);
		}
	}
	return (0);
}
