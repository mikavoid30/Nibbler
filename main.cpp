//
// main.cpp for nibbler in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Mar 22 22:28:37 2015 Mickael BOULAT
// Last update Sun Apr  5 22:55:02 2015 Mickael BOULAT
//

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctype.h>
#include "Snake.hpp"
#include "Exception.hpp"
#include "LibLoader.hpp"


void	Run(LibLoader *loader, int width, int height)
{
  IDisplay	*display;
  t_direction	dir;
  int		i;
  bool		esc;
  Snake		s(width, height);

  i = 0;
  esc = false;
  dir = NONE;
  display = loader->getDisplay();
  if (display->init(s.getWidth(), s.getHeight()) == 1)
    {
      display->run(s);
      while (!(s.isDead()) && !esc)
	{
	  dir = display->getEvent();
	  if (dir == ESC)
	    esc = true;
	  else
	    {
	      s.setDirection(dir);
	      display->run(s);
	      s.move(s.getWidth(), s.getHeight());
	      usleep(s.getSpeed());
	    }
	  ++i;
	}
      if (!esc)
	display->game_over(s);
    }
  display->stop();
}

void	Usage()
{
  std::cout << "Usage: ./nibbler <width> <height> <lib_path>" << std::endl;
}

bool	is_numeric(char *str)
{
  bool	res;

  res = true;
  while (*str && res)
    {
      if (!isdigit(*str))
	res = false;
      ++str;
    }
  return (res);
}

int	Check_Args(char **av, t_config *conf)
{
  int	width;
  int	height;

  width = atoi(av[1]);
  height = atoi(av[2]);
 
  if (width < 0 || height < 0)
	throw Exception("Width and height must be positive");
  else if (!is_numeric(av[1]) || !is_numeric(av[2]))
      throw Exception("Width and height  must be numeric");
  else
    {
      if ((width < MINWIDTH)  || (height  < MINHEIGHT))
	throw Exception("Width or height is/are too short");
      else if ((width  > MAXWIDTH) || (height > MAXHEIGHT))
	throw Exception("Width or height is/are too big");
      else
	{
	  conf->_width = width;
	  conf->_height = height;
	}
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_config	conf;
  LibLoader	*loader = NULL;
  try
    {  
      if (ac == 4)
	{
	  if (Check_Args(av, &conf) == -1)
	    throw Exception("Wrong game size");
	  loader = new LibLoader(av[3]);
	}
      else
	{
	  
	  throw Exception("Usage: ./nibbler <width> <height> <lib_path>");
	}
      Run(loader, conf._width, conf._height);
      if (loader != NULL)
	{
	  loader->closeLib();
	  delete(loader);
	}
    }
  catch(const Exception &e)
    {
      std::cerr << e.what() << std::endl;
      return (-1);
    }

  return (0);
}
