/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:24:14 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 04:18:53 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_dot		*dot(int x, int y)
{
	t_dot	*dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	return (dot);
}

void		draw_line(t_screen *screen, t_dot *p0, t_dot *p1, char c)
{
	t_dot	*d;
	t_dot	*s;
	int		err;
	int		e2;

	d = dot(ft_abs(p1->x - p0->x), ft_abs(p1->y - p0->y));
	s = dot((p0->x < p1->x ? 1 : -1), (p0->y < p1->y ? 1 : -1));
	err = (d->x > d->y ? d->x : -d->y) / 2;
	while (!(p0->x == p1->x && p0->y == p1->y))
	{
		if (p0->x < 200 && p0->x > 0 && p0->y < 50 && p0->y > 0)
			screen->data[p0->y][p0->x] = c;
		e2 = err;
		if (e2 > -d->x)
		{
			err -= d->y;
			p0->x += s->x;
		}
		if (e2 < d->y)
		{
			err += d->x;
			p0->y += s->y;
		}
	}
}

void		tracewire(t_screen *screen, t_wire *wire)
{
	draw_line(screen, dot(wire->a->x, wire->a->y),
						dot(wire->b->x, wire->b->y), '.');
}
