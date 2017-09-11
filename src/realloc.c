/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:37:35 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/11 13:19:02 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int     which_size(size_t size)
{
    if (size < TINY)
        return (TINY);
    else if (size < SMALL)
        return (SMALL);
    else
        return (size);
}

void    *realloc(void *ptr, size_t size)
{
    void *to_free;
    void *addr;

    if ((to_free = ptr_in_list(p->meta, ptr)))
        addr = malloc(size);
    if ((to_free = ptr_in_list(p->large, ptr)))
        addr = malloc(size);
    return (addr);
}
