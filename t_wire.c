/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_wire.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 05:13:31 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		newwire(t_li *li, char *line)
{
	t_wire	*elem;
	char	**tab;

	tab = ft_strsplit(line, '-');
	if (!getroombyname(li, tab[0]) || !getroombyname(li, tab[1]))
	{
		ft_tabfree(tab);
		return (0);
	}
	elem = (t_wire*)malloc(sizeof(t_wire));
	elem->a = getroomptr(li, tab[0], elem, 0);
	elem->b = getroomptr(li, tab[1], elem, 1);
	elem->antpass = 0;
	ft_tabfree(tab);
	if (!elem->a || !elem->b)
	{
		ft_printf("newwire return 0");
		return (0);
	}
	elem->power = -1;
	elem->next = NULL;
	addwire(li, elem);
	return (1);
}

void	addwire(t_li *li, t_wire *wire)
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
