/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:36:24 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/11 16:00:28 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int check_enough_space_memory(size_t size)
{
  int i;

  i = p->size % 4096;
  if (size + i >= 4096)
  {
    p->size += ((4096 - i) + size);
    // printf("size %zu, i %d\n", size, p->size);
    return (1);
  }
  else
  {
    return (0);
  }
}

void *last_ptr(t_metadata *meta)
{
    if (meta == NULL)
        return (NULL);
    int i;

    i = 0;
    while (meta->next != NULL)
    {
        meta = meta->next;
        i++;
    }
    // printf("i %d\n", i);
    return (meta->ptr);
}

t_metadata *meta_insert(t_metadata *meta, size_t size)
{
  t_metadata *tmp;
  t_metadata *tmp2;
  void *ptr;
  int new_page;

  // printf("META INSERT\n");
  new_page = 0;
  //check d'erreur à faire
  if (p->size == 0)
  {
    ptr = mmap(0, getpagesize(), PROT_READ | PROT_WRITE,
                MAP_ANON | MAP_PRIVATE, -1, 0) + 100;
    new_page = 1;
  }
  else
  {
    if (check_enough_space_memory(size) == 1)
    {
      ptr = mmap(0, getpagesize(), PROT_READ | PROT_WRITE,
                  MAP_ANON | MAP_PRIVATE, -1, 0);
      new_page = 1;
      printf("new\n");
    }
  }
  tmp = mmap(0, sizeof(t_metadata), PROT_READ | PROT_WRITE,
      MAP_ANON | MAP_PRIVATE, -1, 0);
  tmp->size = size;
  tmp->next = NULL;
  tmp->free = 0;
  tmp2 = meta;
  if (meta == NULL)
  {
    tmp->ptr = ptr + size;
    tmp->prev = NULL;
    return (tmp);
  }
  else
  {
    if (new_page == 1)
    {
        // printf("last_ptr %p\n", last_ptr(tmp2));
        tmp->ptr = last_ptr(tmp2) + size;
        printf("nouvelle page %d\n", p->size);
    }
    else
    {
        // printf("last_ptr %p\n", last_ptr(tmp2));
        tmp->ptr = last_ptr(tmp2) + size;
        // printf("else %p\n", tmp->ptr);
    }
    while (tmp2->next != NULL)
      tmp2 = tmp2->next;
    tmp2->next = tmp;
    tmp->prev = tmp2;
  }
  return (meta);
}

t_metadata *large_insert(t_metadata *large, size_t size)
{
    t_metadata *tmp;
    t_metadata *tmp2;
    void *ptr;

    //check d'erreur à faire
    ptr = mmap(0, size, PROT_READ | PROT_WRITE,
                MAP_ANON | MAP_PRIVATE, -1, 0);
    tmp = mmap(0, sizeof(t_metadata), PROT_READ | PROT_WRITE,
      MAP_ANON | MAP_PRIVATE, -1, 0);

    tmp->size = size;
    tmp->next = NULL;
    tmp->free = 0;
    tmp2 = large;
    if (large == NULL)
    {

    tmp->ptr = ptr;
    tmp->prev = NULL;
    return (tmp);
    }
    else
    {
        tmp->ptr = tmp2->ptr;
        while (tmp2->next != NULL)
          tmp2 = tmp2->next;
        tmp2->next = tmp;
        tmp->prev = tmp2;
    }
    return (large);
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

void *last_add(t_metadata *meta)
{
  while (meta->next != NULL)
    meta = meta->next;
  printf("l'addresse de retour %p\n", meta->ptr);
  return (meta->ptr - meta->size);
}

void *malloc(size_t size)
{
    printf("BIENVENUE");
  if (p == NULL)
  {
    p =  mmap(0, sizeof(t_p), PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, -1, 0);
    p->size = 0;
  }
  // printf("taille %zu\n", size);
  if (size < TINY)
  {
    // printf("TINY\n");
    p->meta = meta_insert(p->meta, TINY);
    p->size += TINY;
    return (last_add(p->meta));
  }
  else if (size < SMALL)
  {
    // printf("SMALL\n");
    p->meta = meta_insert(p->meta, SMALL);
    p->size += SMALL;
    return (last_add(p->meta));
  }
  else
  {
    // printf("LARGE\n");
    p->large = large_insert(p->large, size);
    return (last_add(p->large));
  }
  // printf("NULL\n");
  return (NULL);
}
