// av[1] = le charactere
// av[2] = le nombre
// ./a.out *42
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
  int i;
  int nb;
  char c;
  char *str;

  nb = atoi(av[2]);
  c = av[1][0];
  str = (char*)mmap(0, nb + 1, PROT_READ | PROT_WRITE,
            MAP_ANON | MAP_PRIVATE, -1, 0);
  i = 0;
  while (i < nb)
  {
    str[i] = c;
    i++;
  }
  str[i] = '\0';
  printf("%s\n", str);
  return (0);
}
