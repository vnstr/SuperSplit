/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 03:18:28 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 03:18:29 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_str.h"

void	init_str(t_split_str *str, char *s, int (*delim_comparator)(int))
{
	str->current = s;
	str->after_protecting = skip_protected(str->current);
	str->delim_comparator = delim_comparator;
}
