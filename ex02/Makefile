NAME = Bureaucrat
CC = g++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++98

SRC =	src/main.cpp \
		src/AForm.cpp \
		src/Bureaucrat.cpp \
		src/RobotomyRequestForm.cpp \
		src/ShrubberyCreationForm.cpp \
		src/PresidentialPardonForm.cpp \

OBJS = $(notdir $(SRC:.cpp=.o))
OBJDIR = Bureaucrat_objects

all: $(OBJDIR) $(NAME)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	$(CC) $(CFLAGS) -o $@ $(addprefix $(OBJDIR)/, $(OBJS))

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
