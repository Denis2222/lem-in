/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 23:07:22 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 12:27:42 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_dot	*dot(int x, int y)
{
	t_dot	*dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	return (dot);
}

void	draw_line(t_screen *screen, t_dot *p0, t_dot *p1, char c)
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
		{
			screen->data[p0->y][p0->x] = c;
		}
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
t_screen *newscreen(int	width, int height)
{
	static t_screen	*screen = NULL;
	int				i;


	i = -1;
	if (screen == NULL)
	{
		screen = (t_screen*)malloc(sizeof(t_screen));
		screen->data = (char**)malloc(sizeof(char*) * (height + 1));
		screen->height = height;
		screen->width = width;
		screen->data[screen->height] = NULL;
		while (++i < screen->height)
		{
			screen->data[i] = (char*)malloc(sizeof(char) * (screen->width + 1));
			ft_bzero(screen->data[i], screen->width);
			ft_memset(screen->data[i], ' ', screen->width -1);
		}
	}
	return (screen);
}

static void putstrscreen(t_screen *screen,char *format, char *txt, int x, int y)
{
	int	len;
	int	i;
	char *str;
	i = 0;

	str = ft_mprintf(format, txt);
	len = ft_strlen(str);
	x = x - (len / 2);
	if (x + i >= 0 && x + len < screen->width)
	{
		if (y > 0 && y < screen->height)
		{
			while (screen->data[y][x + i] && str[i])
			{
				screen->data[y][x + i] = str[i];
				i++;
			}
		}
	}
	str = NULL;
}

static void	viewscreen(t_screen *screen)
{
	int	i;

	i = 0;
	while (screen->data[i])
	{
		ft_printf("%s\n", screen->data[i]);
		i++;
	}
}

void static	tracewire(t_screen *screen, t_wire *wire)
{
	draw_line(screen, dot(wire->a->x, wire->a->y), dot(wire->b->x, wire->b->y), '.');
}

void 	view(t_li *li)
{
	t_room	*room;
	t_rw	*rw;
	t_screen *screen;

	screen = newscreen(140,50);
	room = li->rooms;
	while (room)
	{
		rw = room->wires;
		while (rw)
		{
			if (rwtoroom(rw))
				if (rw->wire->a != rw->wire->b)
					tracewire(screen, rw->wire);
			rw = rw->next;
		}
		room = room->next;
	}
	room = li->rooms;
	while (room)
	{
		rw = room->wires;
		while (rw)
		{
			if (rw->wire->a != rw->wire->b)
			{
				putstrscreen(screen,
					"%s", ft_itoa(rw->wire->power),
					(rw->wire->a->x + rw->wire->b->x) / 2 ,
					(rw->wire->a->y + rw->wire->b->y) / 2 );
				putstrscreen(screen,
					"[%s]", ft_itoa(rw->wire->antpass),
					(rw->wire->a->x + rw->wire->b->x) / 2 - 3,
					(rw->wire->a->y + rw->wire->b->y) / 2 );
			}
			rw = rw->next;
		}
		putstrscreen(screen, "['%s']", room->name, room->x, room->y - 2);
		putstrscreen(screen, "[ %s ]", ft_itoa(get_nb_ant_on_room(li, room)),
			room->x, room->y - 1);
		putstrscreen(screen, "*", room->name, room->x, room->y);
		room = room->next;
	}

	viewscreen(screen);
}
