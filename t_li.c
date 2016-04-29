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

int		ft_streachr(char *str, int (f)(int))
{
	int	i;

	i = 0;
	//ft_printf("IN STREACHR\n");
	while (str[i])
	{
		//ft_printf("Looks at char [%c]\n", str[i]);
		//ft_printf(" is f(%c) : %d\n", str[i], f(str[i]));
		if (!f(str[i]))
			return (0);
		i++;
	}
	return (1);
}


t_li	*new_lem_in(void)
{
	t_list	*stdin;
	t_room	*rooms;
	t_wire	*wires;
	int		ant;
	t_li	*li;

	li = (t_li *)malloc(sizeof(t_li));
	li->ant = 0;
	li->start = NULL;
	li->end = NULL;
	li->rooms = NULL;
	li->wires = NULL;

	ant = 0;
	return (li);
}

int	isant(char *line)
{
	char	**tab;
	int		ok;

	ok = 0;
	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) == 1)
	{
		//ft_printf(" striseachdigit %d", ft_streachr(tab[0], ft_isdigit));
		if (ft_streachr(tab[0], ft_isdigit))
		{
			ok = 1;
		}
	}
	ft_tabfree(tab);
	return (ok);
}

int	isroom(char *line)
{
	char	**tab;
	int		ok;

	ok = 0;
	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) == 3)
		if (ft_streachr(tab[0], ft_isascii) &&
			ft_streachr(tab[1], ft_isdigit) &&
			ft_streachr(tab[2], ft_isdigit))
			ok = 1;
	ft_tabfree(tab);
	return (ok);
}


int	iswire(char *line)
{
	char	**tab;
	int		ok;

	ok = 0;
	tab = ft_strsplit(line, '-');
	if (ft_tablen(tab) == 2)
		if (ft_streachr(tab[0], ft_isascii) &&
			ft_streachr(tab[1], ft_isascii))
			ok = 1;
	ft_tabfree(tab);
	return (ok);
}

void	readstdin(t_li *li)
{
	int		ret;
	char	*line;
	t_list	*elem;
	int		flag[2];

	flag[0] = 0;
	flag[1] = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_printf("%s\n", line);
		if (isant(line))
		{
			li->ant = ft_atoi(line);
			ft_printf("ant");
		}
		if (ft_strequ(line, "##start"))
		{
			flag[0] = 1;
		}
		if (ft_strequ(line, "##end"))
		{
			flag[1] = 1;
		}
		if (isroom(line))
		{
			ft_printf("isroom");
			if (flag[0])
			{
				flag[0] = 0;
				ft_printf(" && start");
			}
			if (flag[1])
			{
				flag[1] = 0;
				ft_printf(" && end");
			}
			ft_printf("\n");
		}
		if (iswire(line))
		{
			ft_printf("iswire");
			ft_printf("\n");
		}
		free(line);
		line = NULL;
	}

}
