/*
** getnextline.c for getnextline.c in /home/Vatoth/CPE_2016_getnextline
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Wed Jan 11 08:40:02 2017 Quentin Sonnefraud
** Last update Mon Feb 27 16:13:34 2017 Vatoth
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "matchstick.h"

void	*my_memset(void *str, int c, size_t n)
{
  char	*d;

  d = str;
  while (n > 0)
    {
      *d++ = c;
      n = n - 1;
    }
  return (str);
}

char	*xrealloc(char *str, size_t size)
{
  char	*my_str;
  int	i;

  i = 0;
  if ((my_str = malloc(size + my_strlen(str))) == NULL)
    return (NULL);
  my_str = my_memset(my_str, '\0', size + my_strlen(str));
  while (str[i])
    {
      my_str[i] = str[i];
      i++;
    }
  free(str);
  return (my_str);
}

int		read_char(const int fd, char *read_c)
{
  static char	buffer[READ_SIZE];
  static int	bytes_reads = 0;
  static int	y = 0;
  static int	stock_fd = -2;
  static int	call = 0;

  if (call == 0)
    {
      stock_fd = fd;
      call = call - 1;
    }
  if (stock_fd != fd)
    return (-2);
  if (bytes_reads == 0)
    {
      if ((bytes_reads = read(fd, buffer, READ_SIZE)) <= 0)
	return (-1);
      y = 0;
    }
  *read_c = buffer[y++];
  bytes_reads--;
  return (0);
}

char	*get_next_line(const int fd)
{
  int	i;
  char	read_c;
  char	*str;
  int	check;

  i = 0;
  read_c = 0;
  check = read_char(fd, &read_c);
  if (check == -2 || check == -1)
    return (NULL);
  if ((str = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  str = my_memset(str, '\0', READ_SIZE + 1);
  while (read_c != '\n')
    {
      str[i++] = read_c;
      if (read_char(fd, &read_c) < 0)
	break ;
      if (i > (READ_SIZE + 1))
	if ((str = xrealloc(str, (i + (READ_SIZE + 1) * sizeof(*str)))) == NULL)
	  return (NULL);
    }
  if (str[i])
    str[i] = '\0';
  return (str);
}
