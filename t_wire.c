/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_wire.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/29 07:26:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void newwire(t_li *li, char *line)
{
	t_wire	*elem;
	char	**tab;

	tab = ft_strsplit(line, '-');

	elem = (t_wire*)malloc(sizeof(t_wire));
	elem->a = getroomptr(li, tab[0], elem, 0);
	elem->b = getroomptr(li, tab[1], elem, 1);
	elem->power = -1;
	elem->next = NULL;
	addwire(li, elem);
}

void addwire(t_li *li, t_wire *wire)
{

	t_wire	*current;

	current = li->wires;
	if (!current)
		li->wires = wire;
	else
	{
		while (current->next)
			current = current->next;
		current->next = wire;
	}
}
