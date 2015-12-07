//
// Exception.cpp for ExceptionCPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 18:24:31 2015 Mickael BOULAT
// Last update Sun Apr  5 18:24:57 2015 Mickael BOULAT
//

# include "Exception.hpp"

Exception::Exception(std::string const &error) throw() : _error(error)
{
}

Exception::~Exception() throw()
{
}

const char *Exception::what() const throw()
{
  return (std::string("Nibbler Error : " + this->_error).c_str());
}

