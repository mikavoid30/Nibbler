//
// IDisplay.hpp for IDisplayHPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 17:58:33 2015 Mickael BOULAT
// Last update Sun Apr  5 20:50:21 2015 Mickael BOULAT
//

# include <iostream>
# include "Exception.hpp"
# include "Snake.hpp"

#  ifndef IDISPLAY_HPP_
#   define IDISPLAY_HPP_

class			IDisplay
{
public:
  virtual ~IDisplay() {};

  virtual void		stop() const = 0;
  virtual t_direction   getEvent() = 0;
  virtual void		run(const Snake &w) = 0;
  virtual int		init(const int w, const int h) = 0;
  virtual void		game_over(const Snake &s) = 0;
  virtual void		create_window(const int w, const int h) = 0;
  virtual void		print_square(const int x, const int y, const int pos) = 0;
};

#  endif /* IDisplay_HPP_ */
