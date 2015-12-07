//
// LibLoader.cpp for LibLoaderCPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 17:43:28 2015 Mickael BOULAT
// Last update Sun Apr  5 18:35:47 2015 Mickael BOULAT
//

# include "LibLoader.hpp"

LibLoader::LibLoader(const char *libName) : _libName(libName)
{
  this->openLib();
}

LibLoader::LibLoader(const LibLoader &other) : _libName(other._libName)
{
  _handle = other._handle;
}

LibLoader	&LibLoader::operator=(const LibLoader &other)
{
  if (this != &other)
    {
      this->_handle = other._handle;
    }
  return (*this);
}

LibLoader::~LibLoader()
{
}

void	LibLoader::openLib()
{
  if ((this->_handle = dlopen(this->_libName, RTLD_LAZY)) == NULL)
    {
      std::cerr << dlerror() << std::endl;
      throw Exception("Opening the library");
    }
}

void	*LibLoader::getSymbol(const char *symbol)
{
  void	*res;
  char	*error;

  res = dlsym(this->_handle, symbol);
  if ((error = dlerror()) != NULL)
    throw Exception(error);
  return (res);
}

void	LibLoader::closeLib()
{
  if (dlclose(this->_handle) != 0)
    {
      throw Exception ("Closing the library");
    }
}


IDisplay	*LibLoader::getDisplay()
{
  IDisplay*	(*external)();

  external = reinterpret_cast<IDisplay* (*)()>(getSymbol("start"));
  return (external());
}
