/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:07:37 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/29 13:49:47 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//gnl
char	*get_next_line(int fd);
char	*read_fd(int fd, char *lines);
char	*ft_update_lines(char *lines);
char	*ft_get_line(char *lines);
size_t	ft_strlen(char *src);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr( char *str, int c);
char	*ft_strdup( char *src);
//ft_printf
int		ft_printf( char *format, ...);
void	ft_putchar(char x, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putnbru(unsigned int nb, int *count);
void	ft_hexconv(unsigned long int nb, char specifier, int *count);

int		ft_atoi( char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int ch);
int		ft_isalpha(int c);
int		ft_isascii(int ch);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr( void *s, int c, size_t n);
int		ft_memcmp( void *s1, void *s2, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dst, void *src, size_t len);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char *string, char delimeter);
char	*ft_strchr( char *str, int c);
char	*ft_strdup( char *src);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(char *src);
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*ft_strnstr(char *big, char *little, size_t len);
char	*ft_strrchr( char *str, int c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char*	ft_strcpy(char* dest, char* src);

#endif