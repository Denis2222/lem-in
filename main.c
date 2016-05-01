/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 07:00:47 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	t_li	*lemin;

	int		coup;
	(void)ac;
	(void)av;
	lemin = new_lem_in();

	readopts(ac, av, lemin->opts, 0);
	readlemin(lemin);
	ft_printf("%s\n", lemin->stdin);
	spore(lemin);
	coup = 0;
	if (lemin->opts['v'])
		viewstate(lemin);
	while (get_nb_ant_on_room(lemin, lemin->end) != lemin->ant)
	{
		ants_move(lemin);
		coup++;
		if (lemin->opts['a'])
		{
			system("clear");
			view(lemin);
			usleep(1000000);
		}
	}
	if (lemin->opts['v'])
		ft_printf("\n{blue}===========\ncoup :%d \n===========\n{eoc}", coup);
	if (lemin->opts['g'])
		view(lemin);
	return (0);
}
