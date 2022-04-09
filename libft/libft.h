/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:23:05 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/01 20:02:23 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_lst_d
{
	void			*content;
	struct s_lst_d	*prev;
	struct s_lst_d	*next;
}					t_lst_d;

void				*ft_memset(void *dest, int c, size_t n);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strchr(const char *str, int c);

char				*ft_strrchr(const char *str, int c);

char				*ft_strnstr(const char *big, const char *little, size_t n);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *ptr);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_calloc(size_t num, size_t size);

char				*ft_strdup(const char *str);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				**ft_split(char const *s, char c);

char				*ft_itoa(int n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *list);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void*));

t_lst_d				*ft_lstdouble_new(void *elem);

t_lst_d				*ft_lstdouble_last(t_lst_d *lst);

void				ft_lstdouble_delone(t_lst_d *lst, void (*del)(void *));

void				ft_lstdouble_clear(t_lst_d **lst, void (*del)(void *));

int					ft_lstdouble_size(t_lst_d *lst);

void				ft_lstdouble_add_front(t_lst_d **head, t_lst_d *new);

void				ft_lstdouble_add_back(t_lst_d **head, t_lst_d *new);

int					get_next_line(int fd, char **line);

size_t				ft_charmtrx_len(char **mtrx);

char				**ft_sub_charmtrx(char **src, int start, int len);

char				**ft_charmtrx_trim(char **mtrx);

char				**ft_realloc_charmtrx(char **arr, size_t size);

void				ft_free_charmtrx(char **mtrx);

void				ft_quicksort(int *array, int left, int right);

char				**ft_charmtrx_dup(char **src);

char				*ft_strrealloc(char *old, size_t new_size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

#endif
