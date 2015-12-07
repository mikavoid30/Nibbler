//
// Snake.cpp for SnakeCPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 17:57:26 2015 Mickael BOULAT
// Last update Sun Apr  5 19:52:52 2015 Mickael BOULAT
//

# include "Snake.hpp"

Snake::Snake(const Snake &other) : _winW(other._winW), _winH(other._winH)
{
}

Snake	&Snake::operator=(const Snake &other)
{
  if (this != &other)
    {
      this->_winW = other._winW;
      this->_winH = other._winH;
    }
  return (*this);
}

s_snakePoint::s_snakePoint(const int x, const int y)
{
  _x = x;
  _y = y;
}

void	Snake::move(const int maxX, const int maxY)
{
  int	hx;
  int	hy;
  
  hx = _body[0]._x;
  hy = _body[0]._y;
  _winW = maxX;
  _winH = maxY;
  if (this->_direction == UP) 
    this->_body.push_front(t_snakePoint(hx, hy - 1));
  else if (this->_direction == RIGHT)
    _body.push_front(t_snakePoint(hx + 1, hy));
  if (this->_direction == DOWN)
    this->_body.push_front(t_snakePoint(hx, hy + 1));
  if (this->_direction == LEFT)
    this->_body.push_front(t_snakePoint(hx - 1, hy));
  if (!checkCollision())
    this->_body.pop_back();  
  if ((hy >= maxY) || (hx >= maxX) || (hy < 0) || (hx < 0))
    _isDead = true;
}

bool		Snake::isDead() const
{
  return (_isDead);
}

bool		Snake::isPartOfSnake(const int x, const int y) const
{
  unsigned int	i;
  bool		res;

  i = 1;
  res = false;
  while (i < _body.size())
    {
      if ((_body[i]._x == x) && (_body[i]._y == y))
	return (true);
      ++i;
    }
  return (res);
}

bool	Snake::isFood(const int x, const int y)
{
  if ((_food._x == x) && (_food._y == y))
    return (true);
  return (false);
}

t_snakePoint	Snake::getFood() const
{
  return (_food);
}

void		Snake::setFood(const int x, const int y)
{
  _food._x = x;
  _food._y = y;
}

bool	Snake::checkCollision()
{
  int	hx;
  int	hy;
  bool	res;

  res = false;
  hx = this->_body[0]._x;
  hy = this->_body[0]._y;
  if (isPartOfSnake(hx, hy))
    _isDead = true;
  else if (isFood(hx, hy))
    {
      _speed -= SNAKE_SPEED_INCREMENT;
      _score += 10;
      if (_speed < SNAKE_MAX_SPEED)
	_speed = SNAKE_MAX_SPEED;
      generateFood();
      res = true;
    }
  return (res);
}

void	Snake::generateFood()
{
  int	food_x;
  int	food_y;

  srand(time(NULL));
  food_x = 2 + rand() % (_winW - 2);
  food_y = 2 + rand() % (_winH - 2);
  while (isPartOfSnake(food_x, food_y))
    {
      food_x = 2 + rand() % (_winW - 2);
      food_y = 2 + rand() % (_winH - 2);
    }
  setFood(food_x, food_y);
}

t_direction	Snake::setDirection(const t_direction dir)
{
  if (dir != NONE && dir != _direction)
    {
      if (_direction == UP && dir == DOWN)
	return (_direction);
      if (_direction == LEFT && dir == RIGHT)
	return (_direction);
      if (_direction == RIGHT && dir == LEFT)
	return (_direction);
      if (_direction == DOWN && dir == UP)
	return (_direction);
      this->_direction = dir;
      if (_direction == UP)
	_head = '^';
      else if (_direction == RIGHT)
	_head = '>';
      else if (_direction == DOWN)
	_head = 'v';
      else
	_head = '<';
    }

  return (_direction);
}

int	Snake::getWidth() const
{
  return (_winW);
}

int	Snake::getHeight() const
{
  return (_winH);
}

t_direction Snake::getDirection() const
{
  return (_direction);
}

int		Snake::getSpeed() const
{
  return (_speed);
}

Snake::Snake(const int width, const int height) : _winW(width), _winH(height)
{
  int	i;

  _isDead = false;
  i = SNAKE_START_SIZE;
  _speed = SNAKE_START_SPEED;
  _score = 0;
  _direction = RIGHT;
  _head = '>';
  generateFood();
  while (i > 0)
    {
      this->_body.push_back(t_snakePoint((width / 2), ((height/2 - (SNAKE_START_SIZE /2)) + --i)));
    }
}

Snake::~Snake()
{
}

