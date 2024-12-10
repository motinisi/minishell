/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogiso <rogiso@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:25:31 by rogiso            #+#    #+#             */
/*   Updated: 2024/04/16 22:25:33 by rogiso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_slice
{
	void	*data;
	size_t	size;
	size_t	length;
	size_t	capacity;
	int		is_heep;
	int		is_error;
}	t_slice;

int		ft_atoi(const char *str);
char	*ft_itoa(int num);
void	ft_bzero(void *dest, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_memset(void *dest, int src, size_t len);
void	*ft_memchr(const void *buffer, int src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int num, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *str, int word);
char	*ft_strrchr(const char *str, int word);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, size_t len);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *str, char sep);
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *str, const char *target, size_t len);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
long	my_atol(const char *str);
long	my_atol_base(const char *str, const char *base);
char	*my_ltoa(long num);
char	*my_ltoa_base(long num, char *base);
size_t	my_strlen(const char *str);
size_t	my_strlen_sep(const char *str, const char sep);
size_t	my_strlcpy(char *dest, const char *src, size_t size);
char	*my_strdup(const char *str);
char	*my_strndup(const char *str, size_t len);
char	*my_strjoin(char *str1, char *str2, int is_heep1, int is_heep2);
char	**my_split(const char *str, char *sep, int has_sep);
size_t	my_count_words_char(const char *str, char sep);
size_t	my_count_words_str(const char *str, char *sep, int has_sep);
size_t	my_strarr_len(char *str[]);
char	**my_strarr_push(char *strs[], char *addstr, int is_heep);
void	my_strarr_delete(char *strs[], size_t start, size_t end);
void	my_strarr_free(char *strs[]);
t_slice	*my_slice_create(size_t size, size_t capacity, int is_heep);
void	my_slice_append(t_slice *slice, void *elem);
void	my_slice_delete(t_slice *slice, size_t start, size_t end);
void	my_slice_free(t_slice **slice);
void	my_error(char *message, int status, int error_num);

#endif
