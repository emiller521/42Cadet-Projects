/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:24:43 by elmiller          #+#    #+#             */
/*   Updated: 2019/03/29 10:08:32 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_numlen(int nbr);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strchr(const char *str, int c);
char				*ft_strnew(size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char *str);
size_t				ft_strlen(const char *str);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
void				ft_bzero(void *str, size_t n);
void				ft_putnbr(int nbr);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memalloc(size_t size);
char				ft_isspace(unsigned char c);
char				*ft_strdup(char const *src);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
char				*ft_strmap(char *str, char (*f)(char));
int					ft_strequ(char *str, char *str1);
char				*ft_strrchr(const char *str, int c);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *str, char const *str1, size_t n);
void				ft_putendl(char *str);
char				*ft_itoa(int n);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void				ft_strclr(char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strtrim(char const *s);
t_list				*ft_lstnew(const void *content, size_t content_size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
int					ft_strcmp(char *dest, char *src);
void				ft_memdel(void **ap);
void				ft_putnbr_fd(int nb, int fd);
char				*ft_strnstr(const char *b, const char *l, size_t len);
int					ft_atoi(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_striter(char *str, void (*f)(char *));
size_t				ft_strlcat(char *dest, char *src, size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
