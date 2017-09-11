/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:10:19 by eozdek            #+#    #+#             */
/*   Updated: 2017/09/11 15:12:49 by eren_ozdek       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main()
{
  char *s;
  char *str;
  int i;
  int nb;
  char c;

  i = 0;
  nb = 42;
  c = 'a';
  s = NULL;
  if ((s = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    return (0);
  }
  while (i < nb)
  {
      s[i] = c;
      i++;
  }
  s[i] = '\0';
  printf("s1 %s\n", s);
  if ((str = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    printf("hello");
    return (0);
  }
  i = 0;
  while (i < nb)
  {
    str[i] = c;
    i++;
  }
  str[i] = '\0';
  char *str1;
  if ((str1 = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    printf("hello");
    return (0);
  }
  i = 0;
  while (i < nb)
  {
    str1[i] = c;
    i++;
  }
  str1[i] = '\0';
  printf("str1 %s\ns %s\n", str1, s);
  char *str2;
  if ((str2 = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    // printf("hello");
    return (0);
  }
  i = 0;
  while (i < nb)
  {
    str2[i] = c;
    i++;
  }
  str2[i] = '\0';
  printf("str2 %s\ns %s\n", str2, s);
  char *sstr3;
  if ((sstr3 = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    // printf("hello");
    return (0);
  }
  i = 0;
  while (i < nb)
  {
    sstr3[i] = c;
    i++;
  }
  sstr3[i] = '\0';
  printf("sstr3 %s\ns %s\n", sstr3, s);
  char *str4;
  if ((str4 = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    // printf("hello");
    return (0);
  }
  i = 0;
  while (i < nb)
  {
    str4[i] = c;
    i++;
  }
  str4[i] = '\0';
  printf("str4 %s\ns %s\n", str4, s);
  char *str5;
  if ((str5 = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    // printf("hello");
    return (0);
  }
  i = 0;
  while (i < nb)
  {
    str5[i] = c;
    i++;
  }
  str5[i] = '\0';
  printf("str5 %s\ns %s\n", str5, s);
  char *str6;
  if ((str6 = (char *)malloc(sizeof(char) * nb + 1)) == NULL)
  {
    // printf("hello");
    return (0);
  }
  i = 0;
  while (i < nb)
  {
    str6[i] = c;
    i++;
  }
  str6[i] = '\0';
  printf("str6 %s\ns %s\n", str6, s);
  // while (i < 200)
  // {
  //     s = malloc(nb);
  //     i++;
  // }
  printf("MAIN %d\n", p->size);
  printf("large %d\n", ft_list_size(p->large));
  printf("meta %d\n", ft_list_size(p->meta));
  printf("lsit %p\n", p->meta->ptr);
  free(s);
  return (0);
}
