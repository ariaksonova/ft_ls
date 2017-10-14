/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:55:12 by maksenov          #+#    #+#             */
/*   Updated: 2017/10/14 16:55:14 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	new_ls(t_ls **ls)
{
	(*ls)->keys.key_all = 0;
	(*ls)->keys.key_list = 0;
	(*ls)->keys.key_recurs = 0;
	(*ls)->keys.key_rev = 0;
	(*ls)->keys.key_time = 0;
	(*ls)->keys.count = 0;
	(*ls)->keys.file = 0;
}

void	find_keys(t_ls *ls, char ***av)
{
	while (**av && (**av)[0] == '-' && (**av)[1])
	{
		(**av)++;
		while (***av)
		{
			if (***av != 'l' && ***av != 'R' && ***av != 'a' &&
***av != 'r' && ***av != 't')
			{
				ft_printf("ft_ls: illegal option -- %c\nusage:"
"ft_ls [-lraRt] [file ...]\n", ***av);
				exit(0);
			}
			***av == 'l' ? ls->keys.key_list = 1 : 0;
			***av == 'r' ? ls->keys.key_rev = 1 : 0;
			***av == 'R' ? ls->keys.key_recurs = 1 : 0;
			***av == 'a' ? ls->keys.key_all = 1 : 0;
			***av == 't' ? ls->keys.key_time = 1 : 0;
			(**av)++;
		}
		(*av)++;
	}
}
