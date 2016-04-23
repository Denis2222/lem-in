/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_li.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 14:34:43 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_li	*new_lem_in(void)
{
	t_list	*stdin;
	t_room	*rooms;
	t_wire	*wires;
	int		ant;
	t_li	*li;

	li = (t_li *)malloc(sizeof(t_li));
	rooms = NULL;
	wires = NULL;
	stdin = NULL;
	ant = 0;
	return (li);
}

void	parsestdin(t_li *li)
{
	t_list	*current;
	char	**tab;

	current = li->stdin;
	while (current)
	{
		tab = ft_strsplit(current->content, ' ');
		if (ft_tablen(tab) != 0)
		{
			if (ft_tablen(tab) == 1 && li->ants == 0)
			{
				li->ants = ft_atoi(tab[0]);
			}
			if (ft_tablen(tab) == 1 && ft_strstr(tab[0], "##"))
			{
				if (ft_strstr(tab[0], "start"))
				{
					ft_printf("start");
				}
				if (ft_strstr(tab[0], "end"))
				{
					ft_printf("end");
				}
			}
			else if (ft_strchr(tab[0], '#'))
			{
				ft_printf("commentaire %s", ft_strchr(tab[0], '#'));
			}
		}
		ft_tabfree(tab);
		current = current->next;
	}
}

void	readstdin(t_li *li)
{
	int		ret;
	char	*line;
	t_list	*elem;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		elem = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 40));
		ft_printf("pointeur:[%p]\n", elem->next);
		ft_lstadd(&li->stdin, elem);
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	//ft_lstrev(li->stdin);
	ft_printf("\n \n ::%p", li->stdin->next->next->next->next->next->next->next->next->next->next);
	//ft_printf("lstlen:%d", ft_lstlen(li->stdin));
	//parsestdin(li);
}
