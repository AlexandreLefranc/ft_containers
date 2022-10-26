# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 18:52:01 by alefranc          #+#    #+#              #
#    Updated: 2022/10/26 18:13:40 by alefranc         ###   ########.fr        #
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

CXX 		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11 -g3

LDFLAGS		=

NS			= ft

#------------------------------------#
#          SOURCES AND CLASSES       #
#------------------------------------#


SRCDIR		=	src/
SRCFILE		=	main.cpp \
				pair.test.cpp \
				equal.test.cpp \
				vector.test.cpp \
				is_integral.test.cpp

SRC			=	$(addprefix $(SRCDIR), $(SRCFILE))

#------------------------------------#
#              INCLUDES              #
#------------------------------------#

INCDIR		=	include/
INCFILE		=	container.hpp \
				equal.hpp \
				equal.tpp \
				is_integral.hpp \
				pair.hpp \
				pair.tpp \
				vector.hpp \
				vector.tpp

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

.PHONY: all
all: $(NAME)_ft

.PHONY: to_std
to_std:
	$(eval NS = std)

.PHONY: to_ft
to_ft:
	$(eval NS = ft)

.PHONY: std
std: clean to_std $(NAME)_$(NS)

.PHONY: ft
ft: clean to_ft $(NAME)_$(NS)

$(NAME)_$(NS): $(OBJ)
	$(CXX) $(CXXFLAGS) -DNS=$(NS) $(LDFLAGS) $(OBJ) -o $(NAME)_$(NS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(INC)
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -DNS=$(NS) -c $< -o $@ -I $(INCDIR)

.PHONY: diff
diff:
	$(MAKE) --quiet ft
	$(MAKE) --quiet std
	./$(NAME)_ft > output.ft.txt
	./$(NAME)_std > output.std.txt
	diff --report-identical-files output.ft.txt output.std.txt
	rm -rf output.ft.txt output.std.txt
	$(MAKE) --quiet fclean

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)_ft
	rm -rf $(NAME)_std

.PHONY: re
re: fclean all