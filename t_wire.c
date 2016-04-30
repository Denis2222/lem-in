/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_wire.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/30 02:38:49 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	newwire(t_li *li, char *line)
{
	t_wire	*elem;
	char	**tab;

	tab = ft_strsplit(line, '-');
	elem = (t_wire*)malloc(sizeof(t_wire));
	elem->a = getroomptr(li, tab[0], elem, 0);
	elem->b = getroomptr(li, tab[1], elem, 1);
	if(!elem->a || !elem->b)
		return (0);
	elem->power = -1;
	elem->next = NULL;
	addwire(li, elem);
	return (1);
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
