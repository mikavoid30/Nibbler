##
## Makefile for nibblr in /home/boulat_m/rendu/Projets_sem2/nibbler
## 
## Made by Mickael BOULAT
## Login   <boulat_m@epitech.net>
## 
## Started on  Mon Mar 23 09:37:06 2015 Mickael BOULAT
## Last update Sun Apr  5 23:21:48 2015 Mickael BOULAT
##

###################################################################
#                            Title & infos
###################################################################

NAME		=	nibbler

###################################################################
#                             Dynamic Lib
###################################################################

LIB_1		=	lib_nibbler_Ncurses.so
LIB_2		=	lib_nibbler_SFML.so

###################################################################
#		              Main Sources
###################################################################

SRCS		=	./Sources/Exception.cpp		\
			./Sources/Snake.cpp		\
			./Sources/LibLoader.cpp		\
			./main.cpp			\

SRCS_1		=	./Sources/Ncurses/Ncurses.cpp
SRCS_2		=	./Sources/SFML/SFML.cpp

###################################################################
#                              Objects
###################################################################

OBJS		=	$(SRCS:.cpp=.o)

OBJS_1		=	$(SRCS_1:.cpp=.o)
OBJS_2		=	$(SRCS_2:.cpp=.o)

###################################################################
#                            Compilation
###################################################################

CC		=	g++

CPPFLAGS	+=	-std=c++11
CPPFLAGS	+=	-W -Wall -Werror
CPPFLAGS	+=      -fPIC
CPPFLAGS	+=	-I./Includes

LDFLAGS		=	-shared

LNCURSES	=	-lncurses
LDL		=	-ldl
LSFML		=	-lsfml-graphics -lsfml-window -lsfml-system

RM		=	rm -rf

###################################################################

all		:	$(NAME)

$(NAME)		:	$(OBJS_1) $(OBJS_2) $(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDL)
			$(CC) $(LDFLAGS) $(LNCURSES) -o ./Libs/$(LIB_1) ./Sources/Ncurses/Ncurses.cpp $(CPPFLAGS)
			$(CC) $(LDFLAGS) $(LSFML) -o ./Libs/$(LIB_2) ./Sources/SFML/SFML.cpp $(CPPFLAGS)

clean		:	
			$(RM) $(OBJS)
			$(RM) $(OBJS_1)
			$(RM) $(OBJS_2)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

###################################################################
###################################################################
###################################################################
