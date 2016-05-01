/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_screen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 23:07:22 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 15:29:12 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_screen	*newscreen(int width, int height)
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
			ft_memset(screen->data[i], ' ', screen->width - 1);
		}
	}
	return (screen);
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

static void	putstrscreen(t_screen *screen, char *format, char *txt, t_dot *dot)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	str = ft_mprintf(format, txt);
	len = ft_strlen(str);
	dot->x = dot->x - (len / 2);
	if (dot->x + i >= 0 && dot->x + len < screen->width)
	{
		if (dot->y > 0 && dot->y < screen->height)
		{
			while (screen->data[dot->y][dot->x + i] && str[i])
			{
				screen->data[dot->y][dot->x + i] = str[i];
				i++;
			}
		}
	}
	str = NULL;
}

void		viewroom(t_li *li, t_screen *screen, t_room *room)
{
	t_rw	*rw;

	rw = room->wires;
	while (rw)
	{
		if (rw->wire->a != rw->wire->b)
		{
			putstrscreen(
				screen,
				"%s",
				ft_itoa(rw->wire->power),
				dot((rw->wire->a->x + rw->wire->b->x) / 2,
				(rw->wire->a->y + rw->wire->b->y) / 2));
			putstrscreen(screen,
				"[%s]", ft_itoa(rw->wire->antpass),
				dot((rw->wire->a->x + rw->wire->b->x) / 2 - 3,
				(rw->wire->a->y + rw->wire->b->y) / 2));
		}
		rw = rw->next;
	}
	putstrscreen(screen, "['%s']", room->name, dot(room->x, room->y - 2));
	putstrscreen(screen, "[ %s ]", ft_itoa(get_nb_ant_on_room(li, room)),
		dot(room->x, room->y - 1));
	putstrscreen(screen, "*", room->name, dot(room->x, room->y));
}

void		view(t_li *li)
{
	t_room		*room;
	t_rw		*rw;
	t_screen	*screen;

	screen = newscreen(140, 50);
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
		viewroom(li, screen, room);
		room = room->next;
	}
	viewscreen(screen);
}
