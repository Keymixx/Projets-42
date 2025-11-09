/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:00:59 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/26 02:55:45 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_puthex(char c, uintptr_t nbr);
int		ft_putnbr_hex(uintptr_t nbr, char *base);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putstr_null(char *str);
int		ft_puthex_null(char c, void *ptr);
int		ft_printf(const char *form, ...);

#endif