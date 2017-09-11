/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:36:53 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/11 00:43:53 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *ptr_in_list(t_metadata *list, void *addr)
{
  void *ptr;

  // ptr = NULL;
  if (list == NULL)
    return (NULL);
  if (list->prev != NULL)
  {
    while (list->prev != NULL)
      list = list->prev;
  }
  while (list != NULL)
  {
    ptr = list->ptr - list->size;
    printf("a %zu\n", list->size);
    printf("addr %p\nptr %p\n", addr, ptr);
    if (ptr == addr)
    {
        printf("hello %d\n", list->free);
        list->free = 1;
        return (list->ptr);
    }
    list = list->next;
  }
  return (NULL);
}

void  free(void *ptr)
{
    int i;
    void *to_free;

    i = 0;
    to_free = NULL;
    printf("FREE");
    printf("%d\n", ft_list_size(p->large));
    if ((to_free = ptr_in_list(p->large, ptr)) != NULL)
    {
        printf("IN LARGE");
    }
    printf("Meta");
    if (ptr_in_list(p->meta, ptr) != NULL)
    {
        printf("IN META");
    }
}
