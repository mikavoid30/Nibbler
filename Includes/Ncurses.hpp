//
// Ncurses.hpp for NcursesHPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 18:46:56 2015 Mickael BOULAT
// Last update Sun Apr  5 20:38:57 2015 Mickael BOULAT
//

# include <iostream>
# include <cstdlib>
# include <unistd.h>
# include <ncurses.h>
# include "Snake.hpp"
# include "IDisplay.hpp"

# ifndef NCURSES_HPP_
#  define NCURSES_HPP_

#  define CUBE_SIZE	1

class			Ncurses : public IDisplay
{
  WINDOW		*_screen;

public:
  Ncurses();
  Ncurses(const Ncurses &other);
  Ncurses		&operator=(const Ncurses &other);
  virtual ~Ncurses();

  virtual void		stop() const;
  virtual t_direction   getEvent();
  virtual void		run(const Snake &w);
  virtual int		init(const int w, const int h);
  virtual void		game_over(const Snake &s);
  virtual void		create_window(const int w, const int h);
  virtual void		print_square(const int x, const int y, const int pos);
};

#endif /* NCURSES_HPP_ */
