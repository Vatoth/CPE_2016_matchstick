/*
** game.c for game.c in /home/vatoth/CPE_2016_matchstick
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Mon Feb 13 12:44:53 2017 Vatoth
** Last update Thu Jun  1 08:36:37 2017 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matchstick.h"

void    printmap(char **map, int len)
{
  int   y;
  int   k;
  int	i;

  y = 0;
  i = 0;
  while (i++ <= len * 2)
    my_printf("*");
  my_printf("\n");
  while (y < len)
    {
      my_printf("*");
      k = 1;
      while (k++ < len - y)
	my_printf(" ");
      my_printf("%s", map[y++]);
      k = 0;
      while (k++ < len - y)
	my_printf(" ");
      my_printf("*\n");
    }
  i = 0;
  while (i++ <= len * 2)
    my_printf("*");
  my_printf("\n\n");
}

char	**allocation(int len)
{
  char  **new_map;
  int   y;
  int	x;

  if ((new_map = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  x = 1;
  y = 0;
  while (y < len)
    {
      if ((new_map[y] = (char *)malloc(sizeof(char) * (x + 1))) == NULL)
	return (NULL);
      new_map[y] = my_memset(new_map[y], '|', (x + 1));
      new_map[y][x] = '\0';
      y++;
      x = x + 2;
    }
  new_map[y] = NULL;
  return (new_map);
}

int	main(int ac, char **av)
{
  char	**map;
  int	len;
  int	max;
  int	output;

  if (ac == 3)
    {
      len = my_atoi(av[1]);
      if (len < 1 || len > 100)
	{
	  fprintf(stderr, "map must be between 1 and 100\n");
	  return (84);
	}
      max = my_atoi(av[2]);
      if ((map = allocation(len)) == NULL)
	{
	  perror("malloc");
	  return (84);
	}
      output = player(map, len, max);
      if (output == -1)
	return (0);
      freetable(map);
      return (output);
    }  
  return (0);
}
