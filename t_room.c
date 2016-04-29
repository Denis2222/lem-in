/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_room.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/29 07:26:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void newroom(t_li *li)
{
	t_room	*elem;
	char	**tab;

	tab = ft_split(line);
	elem = (t_room*)malloc(sizeof(t_room));
	elem->name = ft_strdup(tab[0]);
	elem->x = ft_atoi(tab[1]);
	elem->y = ft_atoi(tab[2]);
	wires = NULL;
	next = NULL;
	//addroom(li, elem);
}
