/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:40:22 by carl              #+#    #+#             */
/*   Updated: 2025/08/19 18:37:13 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

int ft_toupper (int nb);
int ft_strlen(char *str);
void ft_strlcpy (char *dest, char *src);
char *ft_strlcat (char *dest, char *src);
int ft_strncmp (char *s1, char *s2, int len);
char *ft_strnstr(char *big, char *little , int len);
int ft_lower (int nb);
int ft_isprint (int nb);
int ft_isdigit (int nb);
int ft_isascii (int nb);
int ft_isalpha (int nb);
int ft_isalnum (int nb);
int ft_atoi(char *str);

#endif