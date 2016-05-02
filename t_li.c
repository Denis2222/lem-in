/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_li.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 05:03:04 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_li	*new_lemin(void)
{
	t_li	*li;

	li = (t_li *)malloc(sizeof(t_li));
	li->ant = 0;
	li->start = NULL;
	li->end = NULL;
	li->rooms = NULL;
	li->wires = NULL;
	li->usedwires = NULL;
	li->nbusedwires = 0;
	li->ants = NULL;
	li->opts = ft_memalloc('z');
	li->stdin = NULL;
	return (li);
}

void	addstdin(t_li *li, char *line)
{
	char	*str;
	char	*tmp;

	str = li->stdin;
	if (!str)
		str = ft_strjoin("", line);
	else
	{
		tmp = str;
		str = ft_strjoin(str, "\n");
		free(tmp);
		tmp = NULL;
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		tmp = NULL;
	}
	li->stdin = str;
}

void	read_lemin(t_li *li)
{
	int		ret;
	char	*line;
	int		retour;
	int		nbline;

	nbline = 0;
	retour = 0;
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		nbline++;
		retour = lineparser(li, line) + lineparser2(li, line);
		if (retour == 0)
		{
			if (li->opts['v'])
				ft_printf("{red}Error %d line: %d [%s] {eoc}\n",
				retour, nbline, line);
			break ;
		}
		addstdin(li, line);
		free(line);
		line = NULL;
	}
	check_lemin(li);
	li->usedwires = (t_wire **)malloc(sizeof(t_wire) * li->ant);
}

void	check_lemin(t_li *li)
{
	if (!li->rooms || !li->wires || !li->end || !li->start)
	{
		if (li->opts['v'])
		{
			ft_printf("{red}\nSomething is missing ! {eoc}\n");
			if (!li->rooms)
				ft_printf("{red}NO ROOMS {eoc}");
			if (!li->wires)
				ft_printf("{red}NO WIRES {eoc}");
			if (!li->start)
				ft_printf("{red}NO START {eoc}");
			if (!li->end)
				ft_printf("{red}NO END {eoc}");
		}
		else
			ft_printf("ERROR\n");
		exit(0);
	}
}
