/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_li.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/29 08:12:27 by anonymous        ###   ########.fr       */
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

void	draw_line(char **screen, t_dot *p0, t_dot *p1, char c)
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
			screen[p0->y][p0->x] = c;
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

t_li	*new_lem_in(void)
{
	t_li	*li;

	li = (t_li *)malloc(sizeof(t_li));
	li->ant = 0;
	li->start = NULL;
	li->end = NULL;
	li->rooms = NULL;
	li->wires = NULL;
	li->ants = NULL;

	return (li);
}

char 	**newscreen()
{
	char 	**screen;
	int		height;
	int		width;

	height = 50;
	width = 200;
	screen = (char**)malloc(sizeof(char*) * (height + 1));
	screen[height] = NULL;
	while (--height >= 0)
	{
		screen[height] = (char*)malloc(sizeof(char) * (width + 1));
		ft_bzero(screen[height], width);
		ft_memset(screen[height], '`', width -1);
	}
	return screen;
}

void putstrscreen(char **screen,char *format, char *txt, int x, int y)
{
	int	len;
	int	i;
	char *str;
	i = 0;

	str = ft_mprintf(format, txt);
	len = ft_strlen(str);
	x = x - (len / 2);
	if (x + i >= 0)
	{
		if (y > 0)
		{
			while (screen[y][x + i] && str[i])
			{
				screen[y][x + i] = str[i];
				i++;
			}
		}
	}
	str = NULL;
}

void viewscreen(char **screen)
{
	int	i;

	i = 0;
	while (screen[i])
	{
		ft_printf("%s\n", screen[i]);
		i++;
	}
}

void 	tracewire(char **screen, t_wire *wire)
{
	//int	x;
	//int	y;
	//char h;
	//char v;

	//x = wire->a->x - wire->b->x;
	//y = wire->a->y - wire->b->y;

	draw_line(screen, dot(wire->a->x, wire->a->y), dot(wire->b->x, wire->b->y), '.');
}

void 	view(t_li *li)
{
	t_room	*room;
	t_rw	*rw;
	char 	**screen;

	screen = newscreen();
	room = li->rooms;
	while (room)
	{
		rw = room->wires;
		while (rw)
		{
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
					"%s",
					ft_itoa(rw->wire->power),
					(rw->wire->a->x + rw->wire->b->x) / 2 ,
					(rw->wire->a->y + rw->wire->b->y) / 2 );
			}
			rw = rw->next;
		}

		putstrscreen(screen,
			"['%s']",
			room->name,
			room->x,
			room->y - 2);
		putstrscreen(screen,
			"[ %s ]",
			ft_itoa(get_nb_ant_on_room(li, room)),
			room->x,
			room->y - 1);
		putstrscreen(screen,
			"*",
			room->name,
			room->x,
			room->y);
		room = room->next;
	}

	viewscreen(screen);

}

void	readlemin(t_li *li)
{
	int		ret;
	char	*line;
	int		flag[2];

	flag[0] = 0;
	flag[1] = 0;
	ft_printf("Wait gnl().. !");
	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_printf("What ?");
		ft_printf("%s\n", line);
		if (isant(line))
		{
			li->ant = ft_atoi(line);
		}
		else if (ft_strequ(line, "##start"))
		{
			flag[0] = 1;
		}
		else if (ft_strequ(line, "##end"))
		{
			flag[1] = 1;
		}
		else if (ft_strncmp(line, "#", 1) == 0)
		{

		}
		else if (isroom(line))
		{
			if (flag[0])
			{
				flag[0] = 0;
				newroom(li, line, 1);
			}
			else if (flag[1])
			{
				flag[1] = 0;
				newroom(li, line, 2);
			}
			else
			{
				newroom(li, line, 0);
			}
		}
		else if (iswire(line))
		{
			newwire(li, line);
		}
		else
		{
			free(line);
			line = NULL;
			break;
		}
		free(line);
		line = NULL;
	}
	ft_printf("ok");
	populate_ant(li);
}
