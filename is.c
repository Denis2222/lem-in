/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/01 01:53:40 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	isant(char *line)
{
	char	**tab;
	int		ok;

	ok = 0;
	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) == 1)
		if (ft_streachr(tab[0], ft_isdigit))
			ok = 1;
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
