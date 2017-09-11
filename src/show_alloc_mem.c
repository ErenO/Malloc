/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:36:10 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/11 16:29:57 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void  show_alloc_mem()
{
    t_metadata *tmp;
    int i;
    int octet;

    i = 0;
    octet = 0;
    tmp = p->meta;
    if (tmp != NULL)
    {
        printf("TINY : ");
        while (tmp->next != NULL)
        {
            if (tmp->size <= TINY)
            {
                if (i == 0)
                    printf("%p\n", tmp->ptr - tmp->size);
                octet += TINY;
                printf("%p - %p : %d\n", tmp->ptr - tmp->size, tmp->ptr, octet);
                i++;
            }
            tmp = tmp->next;
        }
        if (i == 0)
            printf("\nNONE\n");
        i = 0;
        octet = 0;
        tmp = p->meta;
        printf("SMALL : ");
        while (tmp->next != NULL)
        {
            if (tmp->size <= SMALL)
            {
                if (i == 0)
                    printf("%p\n", tmp->ptr - tmp->size);
                octet += SMALL;
                printf("%p - %p : %d\n", tmp->ptr - tmp->size, tmp->ptr, octet);
                i++;
            }
            tmp = tmp->next;
        }
        if (i == 0)
            printf("NONE");
        octet = 0;
        i = 0;
    }
    tmp = p->large;
    printf("LARGE :\n");
    if (tmp != NULL)
    {
        while (tmp->next != NULL)
        {
            if (i == 0)
                printf("%p\n", tmp->ptr - tmp->size);
            octet += tmp->size;
            printf("LARGE\n%p - %p : %d\n", tmp->ptr - tmp->size, tmp->ptr, octet);
            tmp = tmp->next;
            i++;
        }
    }
    else
    {
        printf("NONE\n");
    }
}
