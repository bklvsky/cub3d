NAME = libft.a

SRCS =	ft_atoi.c \
		ft_isdigit.c \
		ft_lstmap.c \
		ft_putchar_fd.c \
		ft_strjoin.c \
		ft_sub_charmtrx.c \
		ft_bzero.c \
		ft_isprint.c \
		ft_lstnew.c \
		ft_putendl_fd.c \
		ft_strlcat.c \
		ft_substr.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_lstsize.c \
		ft_putnbr_fd.c \
		ft_strlcpy.c \
		ft_tolower.c \
		ft_charmtrx_len.c \
		ft_lstadd_back.c \
		ft_memccpy.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_charmtrx_trim.c \
		ft_lstadd_front.c \
		ft_memchr.c \
		ft_quicksort.c \
		ft_strmapi.c \
		get_next_line.c \
		ft_free_charmtrx.c \
		ft_lstclear.c \
		ft_memcmp.c \
		ft_realloc_charmtrx.c \
		ft_strncmp.c \
		ft_isalnum.c \
		ft_lstdelone.c \
		ft_memcpy.c \
		ft_split.c \
		ft_strnstr.c \
		ft_isalpha.c \
		ft_lstiter.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_isascii.c \
		ft_lstlast.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strtrim.c \
		ft_charmtrx_dup.c \
		ft_strrealloc.c \
		ft_lstdouble_add_back.c \
		ft_lstdouble_add_front.c \
		ft_lstdouble_clear.c \
		ft_lstdouble_delone.c \
		ft_lstdouble_last.c \
		ft_lstdouble_new.c \
		ft_lstdouble_size.c

OBJS = $(SRCS:.c=.o)

INCLUDES = ./

HEADER = libft.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJS): %.o: %.c
		gcc -c $(FLAGS) $< -I$(INCLUDES) -o $@

clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
