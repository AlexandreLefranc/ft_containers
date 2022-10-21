# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 18:52:01 by alefranc          #+#    #+#              #
#    Updated: 2022/10/21 19:45:52 by alefranc         ###   ########.fr        #
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

change_ns:
	@echo called
	@echo $(NS)
	$(eval NS = std)
	@echo $(NS)

stl: change_ns $(NAME)_$(NS)

$(NAME)_ft: $(OBJ_FT)
	$(CXX) $(CXXFLAGS) -DNS=$(NS) $(LDFLAGS) $(OBJ) -o $(NAME)_$(NS)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -DNS=$(NS) $(LDFLAGS) $(OBJ) -o $(NAME)_$(NS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(INC)
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -c -DNS=$(NS) $< -o $@ -I $(INCDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)_*

re: fclean all

print:
	@echo $(OBJ)
	@echo $(OBJ_FT)
	@echo $(OBJ_STD)

.PHONY: all clean fclean re