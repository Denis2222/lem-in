/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:46:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/02 04:45:37 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	strisint(char *str)
{
	if (ft_streachr(str, ft_isdigit))
		return (1);
	if (ft_strlen(str) > 1)
		if (str[0] == '+' || str[0] == '-')
			if (ft_streachr(&str[1], ft_isdigit))
				return (1);
	return (0);
}

int	isant(char *line)
{
	if (ft_streachr(line, ft_isdigit))
		return (1);
	return (0);
}

int	validroomname(char *str)
{
	if (ft_strcountchr(str, '-') == 0)
		if (str[0] != 'L' && str[0] != '#')
			return (1);
	return (0);
}

int	isroom(char *line)
{
	char	**tab;
	int		ok;

	ok = 0;
	if (ft_strcountchr(line, ' ') == 2)
	{
		tab = ft_strsplit(line, ' ');
		if (ft_tablen(tab) == 3)
		{
			if (validroomname(tab[0]) && strisint(tab[1])
				&& strisint(tab[2]))
				ok = 1;
		}
		ft_tabfree(tab);
	}
	return (ok);
}

int	iswire(char *line)
{
	char	**tab;
	int		ok;

	ok = 0;
	if (ft_strcountchr(line, '-') == 1)
	{
		tab = ft_strsplit(line, '-');
		if (ft_tablen(tab) == 2)
		{
			if (validroomname(tab[0]) &&
				validroomname(tab[1]))
				ok = 1;
		}
		ft_tabfree(tab);
	}
	return (ok);
}
