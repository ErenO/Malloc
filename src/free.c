/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:36:53 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/08 16:17:58 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *ptr_in_list(t_metadata *list, void *addr)
{
  void *ptr;

  // ptr = NULL;
  printf("b\n");
  if (list == NULL)
  {
    return (NULL);
  }
  if (list->prev != NULL)
  {
    while (list->prev != NULL)
    {
      list = list->prev;
    }
  }
  printf("c");
  while (list->next != NULL)
  {
    printf("a");
    ptr = list->ptr - list->size;
    if (ptr == addr)
    {
      return (addr);
    }
    list = list->next;
  }
  return (NULL);
}

void  free(void *ptr)
{
  printf("FREE");
  (void)ptr;
  printf("%d\n", ft_list_size(p->large));
  if (ptr_in_list(p->large, ptr) != NULL)
  {
    printf("IN LARGE");
  }
  if (ptr_in_list(p->meta, ptr) != NULL)
  {
    printf("IN META");
  }
}
