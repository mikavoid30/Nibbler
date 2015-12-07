//
// Exception.hpp for ExceptionHPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 18:23:07 2015 Mickael BOULAT
// Last update Sun Apr  5 18:24:59 2015 Mickael BOULAT
//

# include <iostream>
# include <exception>

# ifndef EXCEPTION_HPP_
#  define EXCEPTION_HPP_

class				Exception : public std::exception
{
public :
  Exception(std::string const &msg) throw();
  virtual ~Exception() throw();
  virtual const char *what() const throw();

private:
  std::string _error;
 };

# endif /* EXCEPTION_HPP_ */
