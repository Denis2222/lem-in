/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:30:57 by dmoureu-          #+#    #+#             */
/*   Updated: 2015/12/14 17:59:51 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int		l;
	char	*cstr;

	cstr = (char*)str;
	l = 0;
	while (*cstr)
	{
		cstr++;
		l++;
	}
	return (l);
}
