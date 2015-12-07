//
// Allegro.cpp for allegro in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 09:47:21 2015 Mickael BOULAT
// Last update Sun Apr  5 09:54:01 2015 Mickael BOULAT
//

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Snake.hpp"
#include "Nibbler.hpp"
#include "Allegro.hpp"

Allegro::~Allegro()
{
}

Allegro::Allegro()
{
  init(1, 1);
}
void	Allegro::print_square(int x, int y, int pos)
{
  (void) pos;
  (void) x;
  (void) y;
}

int	Allegro::init(int w, int h)
{
   return (0);
}

void	Allegro::create_window(int w, int h)
{
  (void) w;
  (void) h;
  /*int i = 0;

  _screen.Create(sf::VideoMode(w * CUBE_SIZE, h * CUBE_SIZE, 32), "Allegro Nibbler");
  _back = getSprite("Medias/back.png", sf::Color(0, 255, 255));
  _back->Resize(w * CUBE_SIZE, h * CUBE_SIZE);
  _back->SetPosition(0, 0);
  _screen.Draw(*_back);
  _screen.Display();
  */
}

t_direction Allegro::getEvent()
{
  /*
  t_direction	dir;
  sf::Event	Event;

  dir = NONE;
  if (_screen.GetEvent(Event))
    {
      if (Event.Type == sf::Event::Closed)
        dir = ESC;
      else if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
        dir = ESC;
    }
  if (_screen.GetInput().IsKeyDown(sf::Key::Left))
    dir = LEFT;
  else if (_screen.GetInput().IsKeyDown(sf::Key::Up))
    dir = UP;
  else if (_screen.GetInput().IsKeyDown(sf::Key::Right))
    dir = RIGHT;
  else if (_screen.GetInput().IsKeyDown(sf::Key::Down))
  dir = DOWN;*/
  return NONE;
}

void		Allegro::game_over(Snake &s)
{
  (void) s;
  /*
  _screen.Display();  
  while (go)
    {
      if (_screen.GetEvent(Event))
	{
	  if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Return))
	    go = false;
	}
    }
  */
}

bool	Allegro::start_menu(Snake &s)
{
  return true;
}

void	Allegro::run(Snake &s)
{
  (void) s;
  /* unsigned int	i;

  i = 0;
  _screen.Draw(*_back);
  print_square(s._food._x, s._food._y, -1);
  while (i < s._body.size())
    {
      print_square(s._body[i]._x, s._body[i]._y, i);
      ++i;
    }
  _screen.Display();
  */
}

void	Allegro::debug(int x, int y, const char *data)
{
}

void    Allegro::print_grid(int x, int y) const
{
  (void) x;
  (void) y;
}

void				Allegro::stop()
{
}

bool				Allegro::isOpened() const
{
  return true;
}

void				Allegro::display() const
{
}

  extern "C"
  {
    IDisplay*	start()
    {
      return new Allegro();
    }
  }
