# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 18:52:01 by alefranc          #+#    #+#              #
#    Updated: 2022/11/09 17:33:29 by alefranc         ###   ########.fr        #
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
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3

LDFLAGS		=

NS			= FT

#------------------------------------#
#          SOURCES AND CLASSES       #
#------------------------------------#


SRCDIR		=	src/
SRCFILE		=	main.cpp \
				pair.test.cpp \
				equal.test.cpp \
				vector.test.cpp \
				iterator_traits.test.cpp \
				reverse_iterator.test.cpp \

				# is_integral.test.cpp \
				# enable_if.test.cpp \

SRC			=	$(addprefix $(SRCDIR), $(SRCFILE))

#------------------------------------#
#              INCLUDES              #
#------------------------------------#

INCDIR		=	include/
INCFILE		=	container.hpp \
				enable_if.hpp \
				equal.hpp \
				is_integral.hpp \
				pair.hpp \
				reverse_iterator.hpp \
				vector.hpp vector.tpp

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
all: $(NAME)_$(NS)

.PHONY: to_std
to_std:
	$(eval NS = STD)

.PHONY: to_ft
to_ft:
	$(eval NS = FT)

.PHONY: std
std: clean to_std $(NAME)_$(NS)

.PHONY: ft
ft: clean to_ft $(NAME)_$(NS)

$(NAME)_$(NS): $(OBJ)
	$(CXX) $(CXXFLAGS) -D$(NS) $(LDFLAGS) $(OBJ) -o $(NAME)_$(NS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(INC)
	@mkdir -p `dirname $@`
	$(CXX) $(CXXFLAGS) -D$(NS) -c $< -o $@ -I $(INCDIR)

.PHONY: diff
diff:
	$(MAKE) --quiet ft
	$(MAKE) --quiet std
	./$(NAME)_FT > output.ft.txt
	./$(NAME)_STD > output.std.txt
	-diff output.ft.txt output.std.txt --color --report-identical-files 
	rm -rf output.ft.txt output.std.txt
	$(MAKE) --quiet fclean

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)_FT
	rm -rf $(NAME)_STD

.PHONY: re
re: fclean all