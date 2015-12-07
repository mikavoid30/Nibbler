//
// SFML.cpp for SFMLCPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 17:52:17 2015 Mickael BOULAT
// Last update Sun Apr  5 22:26:07 2015 Mickael BOULAT
//

#include "Exception.hpp"
#include "SFML.hpp"

Sfml	&Sfml::operator=(const Sfml &other)
{
  if (this != &other)
    {
    }
  return (*this);
}

Sfml::~Sfml()
{
}

Sfml::Sfml()
{
}

void	Sfml::print_square(const int x, const int y, const int pos)
{
  sf::Sprite	*s;

  (void) pos;
  if (pos == 0)
    s = getSprite("Medias/head.png", sf::Color(220, 220, 220, 220));
  else if (pos == -1)
    s = getSprite("Medias/food.png", sf::Color(220, 220, 220, 220));
  else
    s = getSprite("Medias/body.png", sf::Color(120, 120, 120, 120));
  s->Resize(CUBE_SIZE, CUBE_SIZE);
  s->SetPosition((x * CUBE_SIZE), (y * CUBE_SIZE));
  _screen.Draw(*s);
}

int	Sfml::init(const int w, const int h)
{
  int	ret;

  ret = 0;
  if (((w * CUBE_SIZE) < (MIN_SIZE * CUBE_SIZE)) || ((w * CUBE_SIZE) > MAXWIDTH))
    {
      std::cerr << "Game size is incorrect, width must be between " << MIN_SIZE << " and " << MAXWIDTH / CUBE_SIZE << " and height must be between " << MIN_SIZE << " and " << MAXHEIGHT / CUBE_SIZE <<  std::endl;
      ret = 0;
    }
  else if ((h * CUBE_SIZE) < (MIN_SIZE * CUBE_SIZE) || (h * CUBE_SIZE) > MAXHEIGHT)
    {
      std::cerr << "Game size is incorrect, width must be between " << MIN_SIZE << " and " << MAXWIDTH << " and height must be between " << MIN_SIZE  << " and " << MAXHEIGHT <<  std::endl;
      ret = 0;
    }  
  else
    {
      ret = 1;
      create_window(w, h);
      _screen.SetFramerateLimit(60);  
    }
  return (ret);
}

sf::Sprite	*Sfml::getSprite(const std::string &file, sf::Color color)
{
  sf::Sprite	*sprite;
  sf::Image	*image;

  sprite = new sf::Sprite();
  image = new sf::Image();
  if (image->LoadFromFile(file) == 0)
    {
      sprite->SetColor(color);
    }
  else  
    {
      sprite->SetImage(*image);
    }
  return sprite;
}

void	Sfml::create_window(const int w, const int h)
{
  _screen.Create(sf::VideoMode(w * CUBE_SIZE, h * CUBE_SIZE, 32), "Sfml Nibbler");
  _back = getSprite("Medias/back.png", sf::Color(0, 255, 255));
  _back->Resize(w * CUBE_SIZE, h * CUBE_SIZE);
  _back->SetPosition(0, 0);
  _screen.Draw(*_back);
  _screen.Display();
}

t_direction Sfml::getEvent()
{
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
    dir = DOWN;
  return dir;
}

void		Sfml::game_over(const Snake &s)
{
  bool		go = true;
  sf::Event	Event;
  sf::Font	Font;
  sf::String	Text;
  sf::String	Text2;
  int		Size;
  float		CenterX;
  float		CenterY;
  
  Size = 30;
  _screen.Draw(*_back);
  Font.LoadFromFile("Medias/slkscrb.ttf");
  Text.SetText("GAME OVER!");
  Text2.SetText("Press Enter to quit.");
  Text.SetFont(Font);
  Text2.SetFont(Font);
  Text.SetSize(Size);
  Text2.SetSize(Size / 2);
  Text2.SetColor(sf::Color(200, 200, 200));
  Text2.SetColor(sf::Color(10, 10, 10));
  CenterX = s._winW / 2;
  CenterY = s._winH / 2;
  Text.Move(CenterX + (Size * 5) , CenterY);
  Text2.Move(CenterX + ((Size / 2) * 10) + 5 , CenterY + (Size * 3));
  _screen.Draw(Text);
  _screen.Draw(Text2);
  _screen.Display();  
  while (go)
    {
      if (_screen.GetEvent(Event))
	{
	  if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Return))
	    go = false;
	}
    }
}

void	Sfml::run(const Snake &s)
{
  unsigned int	i;

  i = 0;
  _screen.Draw(*_back);
  print_square(s._food._x, s._food._y, -1);
  while (i < s._body.size())
    {
      print_square(s._body[i]._x, s._body[i]._y, i);
      ++i;
    }
  _screen.Display();
}

void				Sfml::stop() const
{
}

  extern "C"
  {
    IDisplay*	start()
    {
      return new Sfml();
    }
  }
