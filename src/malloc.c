/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:36:24 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/07 19:10:25 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_data *init_data(t_data *data)
{
  if (data == NULL)
  {

  }
  return (data);
}

t_metadata *meta_insert(t_metadata *meta, size_t size)
{
  t_metadata *tmp;
  t_metadata *tmp2;
  void *p;

  p = NULL;
  //check d'erreur à faire
  if (meta == NULL)
  {
    p = mmap(0, getpagesize(), PROT_READ | PROT_WRITE,
              MAP_ANON | MAP_PRIVATE, -1, 0);
  }
  tmp = mmap(0, sizeof(t_metadata), PROT_READ | PROT_WRITE,
      MAP_ANON | MAP_PRIVATE, -1, 0);
  tmp->size = size;
  tmp->next = NULL;
  tmp2 = meta;
  if (meta == NULL)
  {
    tmp->ptr = p + size;
    tmp->prev = NULL;
    return (tmp);
  }
  else
  {
    tmp->ptr = tmp2->ptr + size;
    while (tmp2->next != NULL)
      tmp2 = tmp2->next;
    tmp2->next = tmp;
    tmp->prev = tmp2;
  }
  return (meta);
}

int		ft_list_size(t_metadata *begin_list)
{
	t_metadata	*tmp;
	int		i;

	i = 1;
	tmp = begin_list;
	if (begin_list == NULL)
		return (0);
  if (tmp->prev != NULL)
    while (tmp->prev != NULL)
      tmp = tmp->prev;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void *last_add()
{
  while (meta->next != NULL)
    meta = meta->next;
  return (meta->ptr);
}

void *malloc(size_t size)
{
  if (size < TINY)
  {
    meta = meta_insert(meta, TINY);
    return (last_add());
  }
  else if (size < SMALL)
  {
    meta = meta_insert(meta, SMALL);
    return (last_add());
  }
  printf("taille %d\n", ft_list_size(meta));
  return (NULL);
}
