/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2019/10/22 13:21:34 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	char	test4 = 'x';
	static char	test5 = 'x';
	unsigned static char	test6 = 'y';
	unsigned char		test7 = 'l';
	int	ret;
/*
ret =	ft_printf("%c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%12c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%12c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%-c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%-c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%-3c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%-3c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%-1c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%-1c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%-2c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%-2c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%-4c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%-4c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%5c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%5c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%3c\n", 'x');
	ft_printf("%d\n", ret);
ret =	printf("%3c\n", 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%-*c\n", 12, 'x');
	ft_printf("%d\n", ret);
ret =	printf("%-*c\n", 12, 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%-*c\n", 18, 'x');
	ft_printf("%d\n", ret);
ret =	printf("%-*c\n", 18, 'x');
	ft_printf("%d\n", ret);
ret =	ft_printf("%*c\n", 12, 'x');
	ft_printf("%d\n", ret);
ret =	printf("%*c\n", 12, 'x');
	ft_printf("%d\n", ret);
*/
//ret =	printf("%*c done!\nbad: %*c\n", 18, 'x', INT_MAX, 'x');
//	printf("%d\n", ret);
//	printf("****************************\n");
ret =	ft_printf("%*c done!\nbad: %*c\n", 18, 'x', INT_MAX, 'x');
//	ft_printf("%d\n", ret);
	return (0);
}
