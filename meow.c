/*
** meow.c for matchstick in /home/vatoth/CPE_2016_matchstick
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Wed Feb 22 16:24:01 2017 Vatoth
** Last update Mon Feb 27 16:25:15 2017 Vatoth
*/

#include "matchstick.h"

int	win(char **map)
{
  int	i;
  int	y;

  y = 0;
  i = 0;
  while (map[y])
    {
      i = i + count_stick(map, y);
      y++;
    }
  if (i == 0)
    return (1);
  return (0);
}

void	delete_stick(char **map, t_pos pos)
{
  int	i;

  i = 0;
  while (map[pos.y][i] == '|')
    i++;
  i--;
  while (pos.x != 0)
    {
      if (map[pos.y][i])
	{
	  map[pos.y][i] = ' ';
	  i--;
	  pos.x--;
	}
    }
}

int	test_number(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] < '0' || s[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int	count_the_one(char **map)
{
  int	x;
  int	y;
  int	i;

  i = 0;
  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x] == '|')
	x++;
      if (x == 1)
	i++;
      y++;
    }
  return (i);
}
