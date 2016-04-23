/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:54:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 11:50:26 by dmoureu-         ###   ########.fr       */
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

	//ft_printf("nb ant:[%d]", lemin->ants);
	return (0);
}
