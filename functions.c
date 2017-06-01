/*
** functions.c for matchstick in /home/vatoth/CPE_2016_matchstick
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Tue Feb 14 12:51:07 2017 Vatoth
** Last update Mon Feb 27 16:07:58 2017 Vatoth
*/

#include <stdlib.h>
#include "matchstick.h"

void    freetable(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

int     my_atoi(char *str)
{
  int   res;
  int   i;

  i = 0;
  res = 0;
  while (str[i])
    res = res * 10 + str[i++] - '0';
  return (res);
}
