//
// SFML.hpp for SFMLHPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 17:52:52 2015 Mickael BOULAT
// Last update Sun Apr  5 22:03:02 2015 Mickael BOULAT
//

# include <iostream>
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include "Exception.hpp"
# include "Snake.hpp"
# include "IDisplay.hpp"

# ifndef SFML_HPP_
#  define SFML_HPP_

#  define CUBE_SIZE		20

class				Sfml : public IDisplay
{
  sf::RenderWindow		_screen;
  sf::Sprite			*_back;
public:
  Sfml();
  Sfml				&operator=(const Sfml &other);
  virtual ~Sfml();

  virtual void			stop() const;
  virtual t_direction		getEvent();
  virtual void			run(const Snake &w);
  virtual int			init(const int w, const int h);
  virtual void			game_over(const Snake &s);
  virtual void			create_window(const int w, const int h);
  virtual void			print_square(const int x, const int y, const int pos);
 sf::Sprite			*getSprite(const std::string &file, sf::Color color); 
};

# endif /* SFML_HPP_ */
