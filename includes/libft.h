/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:37:20 by kbamping          #+#    #+#             */
/*   Updated: 2016/11/29 12:12:17 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef COLOURS
#  define COLOURS
#  define C_NONE         "\033[0m"
#  define C_BOLD         "\033[1m"
#  define C_BLACK        "\033[30m"
#  define C_RED          "\033[31m"
#  define C_GREEN        "\033[32m"
#  define C_BROWN        "\033[33m"
#  define C_BLUE         "\033[34m"
#  define C_MAGENTA      "\033[35m"
#  define C_CYAN         "\033[36m"
#  define C_GRAY         "\033[37m"
# endif

# define BUFF_SIZE	1

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_split_string
{
	size_t		words;
	char		**strings;
}				t_split_string;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strrev(char *str);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strchr_end(char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
char			ft_isupper(char c);
char			ft_islower(char c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			ft_toupper(char c);
char			ft_tolower(char c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnjoin(char const *s1, char const *s2, size_t n_chars);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_ctostr(char c);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_itoa_base(int n, unsigned int base);
char			*ft_uitoa_base(size_t n, unsigned int base);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** NEW FUNCTIONS
*/
void			ft_swap(int *a, int *b);
void			ft_float_swap(float *a, float *b);
void			ft_memswap(void *a, void *b);
int				ft_atoi_hex(const char *nptr);
t_split_string	ft_nstrsplit(const char *s, char c);
t_split_string	ft_nstrsplitstr(const char *s, char *sp);
void			ft_free_split(t_split_string *sp);
char			*ft_strtoupper(char *str);
int				ft_isint(char *str);
char			*ft_strjoinstr(char *s1, char *s2, char *s3);
int				ft_iswhtspc(char c);
char			*ft_strcaps(char *str);
void            ft_strcap(char *str);
int				ft_countarray(char **arr);
int				ft_atoi_hex(const char *nptr);

/*
** GET_NEXT_LINE
*/
int				ft_gnl(const int fd, char **line);

/*
** FT_PRINTF
*/
int				ft_fprintf(int fd, const char *format, ...);
int				ft_sprintf(char **str, const char *format, ...);
int				ft_printf(const char *format, ...);

/*
** LINKED LISTS
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstpushback(t_list **blst, void const *content,
				size_t content_size);
int				ft_lstlen(t_list *blist);
void			ft_lstclear(t_list **list);
t_list			*ft_lstnclear(t_list **list, int nb);
void			ft_lstrev(t_list **begin_list);

#endif
