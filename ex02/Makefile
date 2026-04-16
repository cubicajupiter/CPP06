# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 12:06:00 by jvalkama          #+#    #+#              #
#    Updated: 2026/04/16 19:53:32 by jvalkama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=dynamic

SRCDIR			:=src
VPATH			:=$(SRCDIR)
SRCS			:=main.cpp Base.cpp

OBJDIR			:=obj
OBJS			:=$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

INC			:=inc
INCLUDES		:=-I $(INC)
HEADER			:=$(INC)/A.h $(INC)/B.h $(INC)/C.h $(INC)/Base.h

COMPILER		:=c++
CXXFLAGS		:=-Wall -Wextra -Werror -std=c++20

RM			:=rm -f


all:			$(NAME)

$(OBJDIR):
				mkdir -p $(OBJDIR)

$(NAME):		$(OBJS)
				@echo "linking $@"
				$(COMPILER) $(CXXFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o:		$(SRCDIR)/%.cpp $(HEADER) | $(OBJDIR)
				@echo "Compiling $<"
				$(COMPILER) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
				@echo "Cleaning object files"
				@$(RM) $(OBJS)

fclean:			clean
				@echo "Cleaning all"
				@$(RM) $(NAME)
				@$(RM) -rf $(OBJDIR)

re:			fclean all

.PHONY: all clean fclean re
