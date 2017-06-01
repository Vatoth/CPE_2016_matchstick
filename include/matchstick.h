/*
** matchstick.h for matchstick in /home/vatoth/CPE_2016_matchstick
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Tue Feb 14 11:55:25 2017 Vatoth
** Last update Mon Feb 27 16:14:47 2017 Vatoth
*/

#ifndef MATCHSTICK_H_
# define MATCHSTICK_H_

#include <stdlib.h>

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

void    *my_memset(void *str, int c, size_t n);
int     follow_line(int len, char *s);
int     follow_pos(int max, int x, int count);
int     follow_player(char **map, int max, int len);
void    delete_stick(char **map, t_pos pos);
int     test_number(char *s);
int     win(char **map);
int     possible_line(char **map);
int     count_the_one(char **map);
int     total_xor(char **map);
t_pos   try_xor(char **map, int max, int xor);
t_pos   ia(char **map, int max);
t_pos   take_one(char **map);
int     last_lines(char **map);
int     count_stick(char **map, int y);
t_pos   take_all(char **map, int max);
t_pos   take_the_line(char **map, int max);
void    printmap(char **map, int len);
int     my_atoi(char *str);
int	player(char **map, int len, int max);
char	*get_next_line(int fd);
int	my_strlen(char *str);
int	my_printf(char *flag, ...);
void    freetable(char **tab);

#endif /* !MATCHSTICK_H_ */
