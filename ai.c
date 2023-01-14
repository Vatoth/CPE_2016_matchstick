/*
** ia.c for ia.c in /home/vatoth/CPE_2016_matchstick
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Thu Feb 23 01:44:54 2017 Vatoth
** Last update Thu Jun  1 08:31:58 2017 
*/

#include "matchstick.h"

t_pos   ia(char **map, int max)
{
  int   xor;
  t_pos pos;
  int   odd;

  xor = total_xor(map);
  if (last_lines(map) > 1)
      pos = try_xor(map, max, xor);
  else
    {
      odd = count_the_one(map);
      if (count_the_one(map) == possible_line(map))
	pos = take_one(map);
      else if ((odd % 2) == 0)
	pos = take_the_line(map, max);
      else
	pos = take_all(map, max);
    }
  return (pos);
}

int     total_xor(char **map)
{
  int   x;
  int   y;
  int   xor;

  y = 0;
  xor = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x] == '|')
	x++;
      xor = xor ^ x;
      y++;
    }
  return (xor);
}

t_pos   try_xor(char **map, int max, int xor)
{
  int   y;
  int   x;
  t_pos pos;

  y = -1;
  while (map[++y])
    {
      if (xor == 0 && (count_stick(map, y) > 0))
	{
	  pos.x = 1;
	  pos.y = y;
	  return (pos);
	}
      if ((xor ^ count_stick(map, y)) < count_stick(map, y))
	{
	  x = count_stick(map, y) - (xor ^ count_stick(map, y));
	  while (x > max)
	    x--;
	  pos.x = x;
	  pos.y = y;
	}
    }
  if (pos.x == 0)
    pos.x = 1;
  return (pos);
}

t_pos   take_all(char **map, int max)
{
  int   x;
  int   y;
  t_pos pos = {0, 0};

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x] == '|')
	x++;
      if (x > 1)
	{
	  pos.y = y;
	  pos.x = x;
	  while (pos.x > max)
	    pos.x--;
	  return (pos);
	}
      y++;
    }
  return (pos);
}

t_pos   take_the_line(char **map, int max)
{
  int   x;
  int   y;
  t_pos	pos;

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x] == '|')
	x++;
      pos.x = 0;
      if (x > 1)
	{
	  pos.y = y;
	  pos.x = x - 1;
	  while (pos.x > max)
	    pos.x--;
	  return (pos);
	}
      y++;
    }
  if (pos.x == 0)
    pos.x++;
  return (pos);
}
