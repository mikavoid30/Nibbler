//
// Ncurses.cpp for NcursesCPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 18:46:42 2015 Mickael BOULAT
// Last update Sun Apr  5 23:16:01 2015 Mickael BOULAT
//

# include "Ncurses.hpp"

Ncurses::~Ncurses()
{
  wborder(_screen, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wrefresh(_screen);
  delwin(_screen);
  endwin();
}

Ncurses::Ncurses()
{
}

Ncurses::Ncurses(const Ncurses &other) : _screen(other._screen)
{
}

Ncurses	&Ncurses::operator=(const Ncurses &other)
{
  if (this != &other)
    {
      this->_screen = other._screen;
    }
  return (*this);
}

void		Ncurses::print_square(const int x, const int y, const int pos)
{
  (void) x;
  (void) y;
  (void) pos;
}

int	Ncurses::init(const int w, const int h)
{
  int	color;
  int	maxX;
  int	maxY;
  int	ret;

  ret = 0;
  initscr();
  getmaxyx(stdscr, maxY, maxX);
  if (w < MIN_SIZE || h < MIN_SIZE)
    std::cerr << "Game size is incorrect, please get a higher size for your window. Width must be between " << MIN_SIZE << " and " << maxX<< " and height must be between " << MIN_SIZE << " and " << maxY <<  std::endl;
  else if (w > maxX || h > maxY)
    std::cerr << "Game size is incorrect, please get a higher size for your window. Width must be between " << MIN_SIZE << " and " << maxX<< " and height must be between " << MIN_SIZE << " and " << maxY <<  std::endl;
  else
    {
      ret = 1;
      srand(time(NULL));
      color = rand() % 7;
      start_color();
      raw();
      keypad(stdscr, true);
      noecho();
      nodelay(stdscr, true);
      curs_set(0);
      create_window(w, h);
      box(_screen, 0, 0);
      init_pair(1, color, COLOR_BLACK);
      init_pair(2, COLOR_BLUE, COLOR_BLACK);
      refresh();
    }
  return (ret);
}

void	Ncurses::create_window(const int w, const int h)
{
  _screen = newwin(h, w, 0, 0);
  box(_screen, 0 , 0);	
  wrefresh(_screen);
}

t_direction Ncurses::getEvent()
{
  int	ch;

  ch = getch();
  switch(ch)
    {
    case KEY_LEFT:
      return LEFT;
      break;
    case KEY_RIGHT:
      return RIGHT;
      break;
    case KEY_UP:
      return UP;
      break;
    case KEY_DOWN:
      return DOWN;
      break;
    case 27:
      return ESC;
    default:
      return NONE;
    }
  return NONE;
}

void	Ncurses::game_over(const Snake &s)
{
  int	c;

  c = ERR;
  wclear(_screen);
  box(_screen, 0, 0);
  wattron(_screen, COLOR_PAIR(2) | A_BOLD | A_BLINK);
  mvwprintw(_screen, (s._winH / 2) - 1, ((s._winW / 2) - 6), "Game Over !!");
  mvwprintw(_screen, (s._winH / 2), ((s._winW / 2) - 9), "Your score is %04d", s._score);
  mvwprintw(_screen, (s._winH / 2) + 2, ((s._winW / 2) - 12), "Press any key to exit :)");
  wattroff(_screen, COLOR_PAIR(2) | A_BOLD | A_BLINK); 
  wrefresh(_screen);
  refresh();
  while (c == ERR)
    c = getch();
}

void	Ncurses::run(const Snake &s)
{
  unsigned int i;
  i = 0;
  attron(COLOR_PAIR(2) | A_BOLD);
  wclear(_screen);
  wattron(_screen, COLOR_PAIR(2) | A_BOLD | A_BLINK);
  box(_screen, 0, 0);
  mvprintw(s._winH, ((s._winW / 2) - 6), "Score : %04d", s._score);
  mvwaddch(_screen, s._food._y, s._food._x, '#');
  wattroff(_screen, COLOR_PAIR(2) | A_BOLD | A_BLINK);
  while (i < s._body.size())
    {
      if (i == 0)
	{
	  wattron(_screen, COLOR_PAIR(2) | A_BOLD);
	  mvwaddch(_screen, s._body[i]._y, s._body[i]._x, s._head);
	  wattroff(_screen, COLOR_PAIR(2) | A_BOLD);
	}
      else
	{
	  if (i % 2 == 0)
	    {
	      wattron(_screen, COLOR_PAIR(1) | A_BOLD);
	      mvwaddch(_screen, s._body[i]._y, s._body[i]._x, '#');
	      wattroff(_screen, COLOR_PAIR(1) | A_BOLD);
	    }
	  else
	    {
	      wattron(_screen, COLOR_PAIR(2) | A_BOLD);
	      mvwaddch(_screen, s._body[i]._y, s._body[i]._x, '#');
	      wattroff(_screen, COLOR_PAIR(2) | A_BOLD);
	    }
	}
      ++i;
    }
  attroff(COLOR_PAIR(2) | A_BOLD);
  wrefresh(_screen);
  refresh();  
}

void				Ncurses::stop() const
{
  endwin();
}

  extern "C"
  {
    IDisplay*	start()
    {
      return new Ncurses();
    }
  }
