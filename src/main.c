/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:10:19 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/07 19:10:59 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int ac, char **av)
{
  (void)ac;
  (void)av;

  printf("%p\n", malloc(3));
  printf("%p\n", malloc(100));
  printf("%p\n", malloc(4324345));
  printf("%d\n", ft_list_size(meta));
  return (0);
}
