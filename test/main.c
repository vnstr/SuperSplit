/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:24:21 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 05:54:35 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../include/super_split.h"

void	print_and_free_strs(char **strs)
{
	if (strs == NULL)
	{
		printf("NULL\n");
		return ;
	}
	char	**begin = strs;
	size_t	str_count = 0;
	while (*strs != NULL)
	{
		printf("STR[%zu]: |%s|\n", str_count, *strs);
		free(*strs);
		strs += 1;
		str_count += 1;
	}
	free(begin);
}

int			main(void)
{
	/*
	** Tests
	*/

	int		fd = open("user_output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IREAD | S_IWRITE);

	char	**res;
	char	c;

	//Basic
	printf("~~~ basic ~~~\n");
	c = ';';
	char	*s1 = "123";
	char	*s2 = "123;4567";
	char	*s3 = "123;4567;789123";
	char	*s4 = "12;4567;";
	char	*s5 = ";1;456;789123456";
	char	*s6 = ";1234567;4;";
	char	*s7 = ";1234567;456789;7891;";

	printf("input: |%s|\n", s1);
	res = super_split(s1, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s2);
	res = super_split(s2, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s3);
	res = super_split(s3, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s4);
	res = super_split(s4, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s5);
	res = super_split(s5, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s6);
	res = super_split(s6, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s7);
	res = super_split(s7, c);
	print_and_free_strs(res);
	printf("\n");

	printf("~~~~~~~~~~~~~\n\n");

	//Hard
	printf("~~~ hard ~~~~\n");
	char	*s8 = ";;;;;123;;;;";
	char	*s9 = "12;;;;;;456";
	char	*s10 = "1;;;;;46;;;;;789";
	char	*s11 = "123;;;;;456789;;;;";
	char	*s12 = ";;;;12345;;;;45;;;;7";
	char	*s13 = ";;;;12345;;;;;456789;;;";
	char	*s14 = ";;;;1234;;;;456789;7891234567;;;;";

	printf("input: |%s|\n", s8);
	res = super_split(s8, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s9);
	res = super_split(s9, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s10);
	res = super_split(s10, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s11);
	res = super_split(s11, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s12);
	res = super_split(s12, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s13);
	res = super_split(s13, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s14);
	res = super_split(s14, c);
	print_and_free_strs(res);
	printf("\n");

	printf("~~~~~~~~~~~~~\n\n");

	//BasicWithProtecting
	printf("~~~ Basic With Protecting ~~~\n");
	s1 = "1\\;46"; //1
	s2 = "12'3;4'56"; //1
	s3 = "\"123;456\";789"; //2
	s4 = "123\\\\;456;"; //2
	s5 = ";123\"\";456\'\';789"; //3
	s6 = "\";123;456;\""; //1
	s7 = ";123;45\\\"6;789;"; //3;

	printf("input: |%s|\n", s1);
	res = super_split(s1, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s2);
	res = super_split(s2, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s3);
	res = super_split(s3, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s4);
	res = super_split(s4, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s5);
	res = super_split(s5, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s6);
	res = super_split(s6, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s7);
	res = super_split(s7, c);
	print_and_free_strs(res);
	printf("\n");

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	printf("~~~ Hard With Protecting ~~~~\n");

	s8 = "\'123\\;\\;456\'\\;\';\'789";
	s9 = "\"123;;\";456\\;\\;\'789;\'321";
	s10 = "123\\\';\';;;;\'456\\;\";;;\";78\\;9";
	s11 = "\\\"123;\"456\"\\;;";
	s12 = "\\\"123;\\\'456;789\\;321\';\'654";
	s13 = "\\;123\\;\';;;;\'\\;;456\'\';\"\";\";\"789";
	s14 = "\\'123;\'456;\';768\\;1";

	printf("input: |%s|\n", s8);
	res = super_split(s8, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s9);
	res = super_split(s9, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s10);
	res = super_split(s10, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s11);
	res = super_split(s11, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s12);
	res = super_split(s12, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s13);
	res = super_split(s13, c);
	print_and_free_strs(res);
	printf("\n");

	printf("input: |%s|\n", s14);
	res = super_split(s14, c);
	print_and_free_strs(res);
	printf("\n");


	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	//mutant_split(argv[1], ';');
	return (0);
}

