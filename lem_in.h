/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:55:44 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/29 07:50:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct			s_li_room
{
	char				*name;
	struct s_li_wire	*wires;
	struct s_li_room	*next;
	int					x;
	int					y;
}						t_room;

typedef struct			s_li_wire
{
	t_room				*a;
	t_room				*b;
	struct s_li_wire	*next;
}						t_wire;

typedef struct			s_lem_in
{
	int					ant;
	t_room				*start;
	t_room				*end;
	t_room				*rooms;
	t_wire				*wires;
}						t_li;

t_li	*new_lem_in(void);
void	readstdin(t_li *li);

int		ft_streachr(char *str, int (f)(int));

#endif
