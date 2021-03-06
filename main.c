/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 12:39:48 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bonus(t_li *lemin)
{
	if (lemin->opts['a'])
	{
		system("clear");
		view(lemin);
		sleep(1);
	}
}

int		main(int ac, char **av)
{
	t_li	*lemin;
	int		coup;

	lemin = new_lemin();
	readopts(ac, av, lemin->opts, 0);
	read_lemin(lemin);
	spore(lemin);
	ft_printf("%s\n", lemin->stdin);
	coup = 0;
	if (lemin->opts['v'])
		viewstate(lemin);
	while (get_nb_ant_on_room(lemin, lemin->end) != lemin->ant)
	{
		ants_move(lemin);
		coup++;
		bonus(lemin);
	}
	if (lemin->opts['v'])
		ft_printf("\n{blue}===========\ncoup :%d \n===========\n{eoc}", coup);
	if (lemin->opts['g'])
		view(lemin);
	return (0);
}
