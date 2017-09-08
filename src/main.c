/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:10:19 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/08 16:07:31 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int ac, char **av)
{
  (void)ac;
  (void)av;
  char *s;
  int i;
  int nb;
  char c;

  i = 0;
  nb = 0;
  nb = atoi(av[2]);
  c = av[1][0];
  s = NULL;
  if ((s = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    printf("hello");
    return (0);
  }
  while (i < nb)
  {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  // while (i < 200)
  // {
  //   if (i % 2)
  //     malloc(30);
  //   else
  //     malloc(100);
  //   i++;
  // }
  printf("MAIN %d\n", p->size);
  printf("large %d\n", ft_list_size(p->large));
  printf("meta %d\n", ft_list_size(p->meta));
  free(s);
  return (0);
}
