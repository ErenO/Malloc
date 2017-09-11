/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:37:35 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/11 17:26:37 by eozdek           ###   ########.fr       */
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
    {
        // free(to_free);
        addr = malloc(size);
        printf("reac addr %p\n", addr);
    }
    if ((to_free = ptr_in_list(p->large, ptr)))
    {
        // free(to_free);
        addr = malloc(size);
    }
    return (addr);
}
