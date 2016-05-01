/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 02:22:40 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 08:35:42 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	readoptsargs(char **av, char *opts, int i)
{
	const char	args[7] = {'v', 'g', 'a', '1'};

	while (ft_strchr(args, *av[i]) && *av[i] != 0)
	{
		opts[(int)(*av[i])] = 1;
		(av[i]++);
	}
	write(1, "", 0);
	if (*av[i] != '\0')
	{
		ft_printf("ls: illegal option -- %s", av[i]);
		exit(1);
	}
}

int		readopts(int ac, char **av, char *opts, int i)
{
	while (++i < ac)
	{
		if (*av[i] == '-')
		{
			av[i]++;
			if (*av[i] == '\0')
			{
				write(1, "", 0);
				av[i]--;
				return (i);
			}
			if (*av[i] == '-')
			{
				if (*(++av[i]) == '\0')
					return (i + 1);
				else
					ft_printf("ft_ls: illegal option -- %s", --av[i]);
			}
			readoptsargs(av, opts, i);
		}
		else
			return (i);
	}
	return (i);
}
