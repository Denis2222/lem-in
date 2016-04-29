/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/29 08:09:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	t_li	*lemin;

	(void)ac;
	(void)av;
	lemin = new_lem_in();
	readstdin(lemin);


	ft_printf("===============================================\n");
	ft_printf("==========%d=====================================\n", lemin->ant);

	//ft_printf("nb ant:[%d]", lemin->ants);
	return (0);
}
