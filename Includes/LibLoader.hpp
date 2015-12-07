//
// LibLoader.hpp for LibLoaderHPP in /home/boulat_m/rendu/Projets_sem2/nibbler
// 
// Made by Mickael BOULAT
// Login   <boulat_m@epitech.net>
// 
// Started on  Sun Apr  5 17:43:46 2015 Mickael BOULAT
// Last update Sun Apr  5 20:57:16 2015 Mickael BOULAT
//

# include <iostream>
# include <dlfcn.h>
//# include <cstdlib>
# include "Exception.hpp"
# include "IDisplay.hpp"

# ifndef LIBLOADER_HPP_
#  define LIBLOADER_HPP_

class				LibLoader
{
  void				*_handle;
  const char			*_libName;
 
public :
				LibLoader(const char *libname);
				LibLoader(const LibLoader &other);
  LibLoader			&operator=(const LibLoader &other);
				~LibLoader();
  
  void				openLib();
  void				closeLib();
  void				*getSymbol(const char *symbol);
  IDisplay	      		*getDisplay();
 };

# endif /* LIBLOADER_HPP_ */
