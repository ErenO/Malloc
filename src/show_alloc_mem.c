/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:36:10 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/11 15:58:05 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void  show_alloc_mem()
{
    t_metadata *tmp;

    tmp = p->meta;
    while (tmp->next != NULL)
    {
        if (tmp->size <= TINY)
        {
            printf("TINY\n%p - %p\n", tmp->ptr - tmp->size, tmp->ptr);
        }
        else if (tmp->size <= SMALL)
        {
            printf("SMALL\n%p - %p\n", tmp->ptr - tmp->size, tmp->ptr);
        }
        tmp = tmp->next;
    }
    tmp = p->large;
    while (tmp->next != NULL)
    {
        printf("LARGE\n%p - %p\n", tmp->ptr - tmp->size, tmp->ptr);
        tmp = tmp->next;
    }
}
