/*
** player.c for matchstick in /home/vatoth/CPE_2016_matchstick
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Tue Feb 14 13:56:07 2017 Vatoth
** Last update Mon Feb 27 16:23:58 2017 Vatoth
*/

#include <stdlib.h>
#include "matchstick.h"

int	take_pos(char **map, int y, int max)
{
  char	*s;
  int	x;
  int	count;

  x = 0;
  while (map[y][x] == '|')
    x++;
  count = x;
  my_printf("Matches: ");
  if ((s = get_next_line(0)) == NULL)
    return (-2);
  if (test_number(s) == -1 || my_strlen(s) == 0)
    {
      free(s);
      my_printf("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  x = my_atoi(s);
  if (follow_pos(max, x, count) == -1)
    {
      free(s);
      return (-1);
    }
  free(s);
  return (x);
}

int	follow_pos(int max, int x, int count)
{
  if (x > max)
    {
      my_printf("Error: you cannot remove more than ");
      my_printf("%i matches per turn\n", max);
      return (-1);
    }
  if (x == 0)
    {
      my_printf("Error: you have to remove at least one match\n");
      return (-1);
    }
  if (x > count)
    {
      my_printf("Error: not enough matches on this line\n");
      return (-1);
    }
  return (x);
}

t_pos 	take_line(char **map, int max, int len)
{
  char	*s;
  t_pos	pos;
  int	a;

  my_printf("Line: ");
  if ((s = get_next_line(0)) == NULL)
    {
      pos.x = -1;
      return (pos);
    }
  if ((pos.y = follow_line(len, s)) == -1)
    {
      free(s);
      return (take_line(map, max, len));
    }
  if ((a = take_pos(map, pos.y,  max)) == -1)
    {
      free(s);
      return (take_line(map, max, len));
    }
  free(s);
  pos.x = a;
  return (pos);
}

int	follow_line(int len, char *s)
{
  int	y;

  if (test_number(s) == -1 || my_strlen(s) == 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  y = my_atoi(s) - 1;
  if (y < 0 || y + 1 > len)
    {
      my_printf("Error: this line is out of range\n");
      return (-1);
    }
  return (y);
}

int	player(char **map, int len, int max)
{
  t_pos	pos;
  int	test;

  printmap(map, len);
  while (42)
    {
      my_printf("Your turn:\n");
      pos = take_line(map, max, len);
      if (pos.x <= 0)
	return (-1);
      my_printf("Player removed ");
      my_printf("%i match(es) from line %i\n", pos.x, pos.y + 1);
      delete_stick(map, pos);
      printmap(map, len);
      if (win(map) == 1)
	{
	  my_printf("You lost, too bad...\n");
	  return (2);
	}
      test = follow_player(map, max, len);
      if (test == 1)
	return (1);
    }
  return (0);
}
