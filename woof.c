/*
** woof.c for matchstick in /home/vatoth/CPE_2016_matchstick
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Thu Feb 23 01:41:20 2017 Vatoth
** Last update Mon Feb 27 16:18:40 2017 Vatoth
*/

#include "matchstick.h"

int	follow_player(char **map, int max, int len)
{
  t_pos	pos;

  my_printf("AI's turn...\n");
  pos = ia(map, max);
  delete_stick(map, pos);
  my_printf("AI removed %i match(es) from line %i\n", pos.x, pos.y + 1);
  printmap(map, len);
  if (win(map) == 1)
    {
      my_printf("I lost... snif... but I’ll get you next time!!\n");
      return (1);
    }
  return (0);
}

int	last_lines(char **map)
{
  int	x;
  int	y;
  int	rest_line;

  y = 0;
  rest_line = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x] == '|')
	x++;
      if (x > 1)
	rest_line++;
      y++;
    }
  return (rest_line);
}

int     count_stick(char **map, int y)
{
  int   x;

  x = 0;
  while (map[y][x] == '|')
    x++;
  return (x);
}

int     possible_line(char **map)
{
  int   y;
  int	x;

  y = 0;
  x = 0;
  while (map[y])
    {
      if (map[y][0] == '|')
	x++;
      y++;
    }
  return (x);
}

t_pos   take_one(char **map)
{
  int	y;
  t_pos pos;

  y = 0;
  pos.x = 0;
  while (map[y])
    {
      if ((count_stick(map, y) == 1))
	{
	  pos.x = 1;
	  pos.y = y;
	  return (pos);
	}
      y++;
    }
  return (pos);
}
