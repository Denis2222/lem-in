/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_li.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 15:35:22 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_li	*new_lem_in(void)
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

int		lineparser2(t_li *li, char *line)
{
	if (isant(line))
	{
		li->ant = ft_atoi(line);
		return (1);
	}
	else if (ft_strncmp(line, "#", 1) == 0)
		return (4);
	else if (iswire(line))
		return (newwire(li, line));
	return (0);
}

int		lineparser(t_li *li, char *line)
{
	static int	flag = 0;

	if (ft_strequ(line, "##start"))
	{
		flag = 1;
		return (2);
	}
	else if (ft_strequ(line, "##end"))
	{
		flag = 2;
		return (3);
	}
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

void	readlemin(t_li *li)
{
	int		ret;
	char	*line;
	int		retour;

	retour = 0;
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		addstdin(li, line);
		retour = lineparser(li, line) + lineparser2(li, line);
		if (retour == 0)
			break ;
		free(line);
		line = NULL;
	}
	if (!li->rooms || !li->wires || !li->end || !li->start)
	{
		ft_printf("ERROR {red}[t_li parser]{eoc}\n");
		exit(0);
	}
	li->usedwires = (t_wire **)malloc(sizeof(t_wire) * li->ant);
}
