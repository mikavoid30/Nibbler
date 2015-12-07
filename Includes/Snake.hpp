//
// Snake.hpp for SnakeHPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 17:57:12 2015 Mickael BOULAT
// Last update Thu Apr  9 21:35:43 2015 Mickael BOULAT
//

# include <iostream>
# include <deque>
# include <time.h>
# include <unistd.h>
# include "Exception.hpp"

#  ifndef SNAKE_HPP_
#   define SNAKE_HPP_

#   define MIN_SIZE		20
#   define MINHEIGHT		10
#   define MINWIDTH		10
#   define MAXWIDTH		900
#   define MAXHEIGHT		900
#   define SNAKE_START_SIZE	20
#   define SNAKE_START_SPEED	150000
#   define SNAKE_MAX_SPEED	30000
#   define SNAKE_SPEED_INCREMENT	5000

typedef struct			s_snakePoint
{
  int				_x;
  int				_y;
  s_snakePoint(const int x = 0, const int y = 0);
}				t_snakePoint;

typedef struct			s_config
{
  int				_width;
  int				_height;
}				t_config;

typedef enum {NONE, UP, RIGHT, DOWN, LEFT, ESC} t_direction;

class				Snake
{
  int				_size;
  t_direction			_direction;
  int				_speed;
  bool				_isDead;

public :
  std::deque<t_snakePoint>    	_body;
  t_snakePoint			_food;
  int				_winW;
  int				_winH;
  int				_score;
  char				_head;

  Snake(const int width, const int height);
  Snake(const Snake &other);
  ~Snake();
  Snake				&operator=(const Snake &other);

  void				move(const int x, const int y);
  bool				isDead() const;
  bool				isPartOfSnake(const int x, const int y) const;
  bool				isFood(const int x, const int y);
  t_snakePoint			getFood() const;
  void				setFood(const int x, const int y);
  bool				checkCollision();
  void				generateFood();
  t_direction			setDirection(const t_direction dir);
  t_direction			getDirection() const;
  int				getSpeed() const;
  int				getWidth() const;
  int				getHeight() const;
 };

#  endif /* SNAKE_HPP_ */
