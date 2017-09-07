/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:10:28 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/07 19:04:31 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define TINY 32
# define SMALL 128
# include <stdio.h>
# include <stdint.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <sys/mman.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_metadata t_metadata;
typedef struct s_data t_data;
void *p;
t_metadata *meta;

typedef struct  s_metadata
{
  size_t		size;
  t_metadata       *next;
  t_metadata       *prev;
  int free;
  void *ptr;
}               t_metadata;

typedef struct  s_data
{
  size_t		size;
  t_data       *next;
  t_data       *prev;
  int free;
  void *ptr;
}               t_data;

int		ft_list_size(t_metadata *begin_list);
void show_alloc_mem();
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

#endif
