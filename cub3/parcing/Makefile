NAME = cub3d
CFILES = cub.c \
		 ft_atoi.c \
		 ft_split.c \
		 ft_strncmp.c \
		 get_next_line.c \
		 read_map.c \
		 ft_strtrim.c \
		 ft_substr.c \
		 helper1.c \
		 helper2.c \
		 helper3.c

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address 
COM = cc
RM = rm -rf

OBJ= $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(CFLAGS) $(OBJ) -o $(NAME)  

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:    fclean all