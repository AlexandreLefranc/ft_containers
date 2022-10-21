# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 18:52:01 by alefranc          #+#    #+#              #
#    Updated: 2022/10/21 20:18:15 by alefranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                                                              #
#                               DECLARATIONS                                   #
#                                                                              #
#------------------------------------------------------------------------------#

#------------------------------------#
#             COMPILATION            #
#------------------------------------#

NAME = containers

# CC			= gcc
# CFLAGS		= -Wall -Wextra -Werror -g3

CXX 		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3

LDFLAGS		=

NS			= ft

#------------------------------------#
#          SOURCES AND CLASSES       #
#------------------------------------#


SRCDIR		=	src/
SRCFILE		=	main.cpp \
				pair.test.cpp \
				equal.test.cpp

SRC			=	$(addprefix $(SRCDIR), $(SRCFILE))

#------------------------------------#
#              INCLUDES              #
#------------------------------------#

INCDIR		=	include/
INCFILE		=	container.hpp \
				pair.hpp \
				pair.tpp \
				equal.hpp \
				equal.tpp \

INC			=	$(addprefix $(INCDIR), $(INCFILE))

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJDIR		=	obj/
OBJ			=	$(subst $(SRCDIR),$(OBJDIR),$(SRC:.cpp=.o))
OBJ_FT		=	$(OBJ:.o=_ft.o)
OBJ_STD		=	$(OBJ:.o=_std.o)

#------------------------------------------------------------------------------#
#                                                                              #
#                                   RULES                                      #
#                                                                              #
#------------------------------------------------------------------------------#

all: $(NAME)_ft

to_std:
	$(eval NS = std)

to_ft:
	$(eval NS = ft)

std: clean to_std $(NAME)_$(NS)

ft: clean to_ft $(NAME)_$(NS)

$(NAME)_$(NS): $(OBJ)
	$(CXX) $(CXXFLAGS) -DNS=$(NS) $(LDFLAGS) $(OBJ) -o $(NAME)_$(NS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(INC)
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -DNS=$(NS) -c $< -o $@ -I $(INCDIR)

diff:
	$(MAKE) ft
	$(MAKE) std
	./$(NAME)_ft > output.ft.txt
	./$(NAME)_std > output.std.txt
	diff output.ft.txt output.std.txt
	rm -rf output.ft.txt output.std.txt

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)_ft
	rm -rf $(NAME)_std

re: fclean all

print:
	@echo $(MAKE)

.PHONY: all clean fclean re to_std to_ft std ft diff