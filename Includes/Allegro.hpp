//
// LibLoader.hpp for loader in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Mon Mar 23 18:18:14 2015 Mickael BOULAT
// Last update Sun Apr  5 10:40:37 2015 Mickael BOULAT
//

#include <iostream>
#include <dlfcn.h>
#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_image.h>
#include "Exception.hpp"
#include "Snake.hpp"
#include "Nibbler.hpp"
#include "IDisplay.hpp"

#ifndef ALLEGRO_HPP_
# define ALLEGRO_HPP_

# define CUBE_SIZE	20

class                 Allegro : public IDisplay
{
  sf::RenderWindow		_screen;
  sf::Sprite			*_back;
  World				*_world;
public:
  Allegro();
  virtual ~Allegro();
  virtual void		stop();
  virtual bool		isOpened() const;
  virtual t_direction   getEvent();
  virtual void		display() const;
  virtual void		run(Snake &w);
  virtual int		init(int w, int h);
  void		       	create_window(int w, int h);
  void			print_square(int x, int y, int pos);
  void			print_grid(int x, int y) const;
  virtual void		debug(int x, int y, const char *data);
  virtual void		game_over(Snake &s);
  virtual bool	       	start_menu(Snake &s);
};

#endif /* ALLEGRO_HPP_ */
