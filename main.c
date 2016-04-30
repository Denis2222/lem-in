/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/30 03:27:35 by dmoureu-         ###   ########.fr       */
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
	readlemin(lemin);
	spore(lemin);
	coup = 0;
	while (get_nb_ant_on_room(lemin, lemin->end) != lemin->ant)
	{
		ants_move(lemin);
		coup++;
		//view(lemin);
		//usleep(1000000);
	}
	ft_printf("\n{blue}=====================\ncoup :%d \n=====================\n{eoc}", coup);
	return (0);
}
