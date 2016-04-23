/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:55:44 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 11:39:31 by dmoureu-         ###   ########.fr       */
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
}						t_room;

typedef struct			s_li_wire
{
	t_room				*a;
	t_room				*b;
	struct s_li_wire	*next;
}						t_wire;

typedef struct			s_lem_in
{
	t_list				*stdin;
	t_room				*rooms;
	t_wire				*wires;
	int					ants;
}						t_li;

t_li	*new_lem_in(void);
void	readstdin(t_li *li);

#endif
