/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:23:50 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/21 00:12:45 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
// void ft_print_list (t_list **lst)
// {
// 	t_list	*cpylst;

// 	cpylst = *lst; 
// 	if(!*lst)
// 		printf("Pas de liste\n");
// 	while (cpylst != NULL)
// 	{
// 		printf("%s\n",(char *)cpylst->content);
// 		cpylst = cpylst->next;
// 	}
// }

int	main(void)
{
	printf("FT_ATOI\n");
	
	printf("Mine : %d\n",ft_atoi("0"));
	printf("Real : %d\n\n",atoi("0"));
	printf("Mine : %d\n",ft_atoi("2147483648"));
	printf("Real : %d\n\n",atoi("2147483648"));
	printf("Mine : %d\n",ft_atoi("2147483647"));
	printf("Real : %d\n\n",atoi("2147483647"));
	printf("Mine : %d\n",ft_atoi("--41421"));
	printf("Real : %d\n\n",atoi("--41421"));
	printf("Mine : %d\n",ft_atoi("\007 8"));
	printf("Real : %d\n\n\n",atoi("\007 8"));

	printf("FT_ISALNUM\n");

	printf("Mine : %d\n",ft_isalnum('4'));
	printf("Real : %d\n\n",isalnum('4'));
	printf("Mine : %d\n",ft_isalnum('f'));
	printf("Real : %d\n\n",isalnum('f'));
	printf("Mine : %d\n",ft_isalnum('='));
	printf("Real : %d\n\n",isalnum('='));
	printf("Mine : %d\n",ft_isalnum('@'));
	printf("Real : %d\n\n\n",isalnum('@'));

	printf("FT_ISAPRINT\n");

	printf("Mine : %d\n",ft_isprint('4'));
	printf("Real : %d\n\n",isprint('4'));
	printf("Mine : %d\n",ft_isprint('f'));
	printf("Real : %d\n\n",isprint('f'));
	printf("Mine : %d\n",ft_isprint('~' + 1));
	printf("Real : %d\n\n",isprint('~' + 1));
	printf("Mine : %d\n",ft_isprint('\n'));
	printf("Real : %d\n\n\n",isprint('\n'));

	printf("FT_ASCII\n");

	printf("Mine : %d\n",ft_isascii('4'));
	printf("Real : %d\n\n",isascii('4'));
	printf("Mine : %d\n",ft_isascii('f'));
	printf("Real : %d\n\n",isascii('f'));
	printf("Mine : %d\n",ft_isascii(' '));
	printf("Real : %d\n\n",isascii(' '));
	printf("Mine : %d\n",ft_isascii('\n'));
	printf("Real : %d\n\n\n",isascii('\n'));

	printf("FT_ITOA\n");

	printf("123456 : %s\n",ft_itoa(123456));
	printf("-908543 : %s\n",ft_itoa(-908543));
	printf("-2147483648 : %s\n",ft_itoa(-2147483648));
	printf("2147483647 : %s\n",ft_itoa(2147483647));
	printf("421 : %s\n\n\n",ft_itoa(421));

	printf("FT_MEMCHR\n");
	
	char MEMCHR[30] = "Coucou ca va ?";
	printf("Mine : %s \n",(char *)ft_memchr(MEMCHR, '=', sizeof(char) * 15));
	printf("Real : %s \n\n",(char *)memchr(MEMCHR, '=', sizeof(char) * 15));
	printf("Mine : %s \n",(char *)ft_memchr(MEMCHR, '=', sizeof(char) * 13));
	printf("Real : %s \n\n",(char *)memchr(MEMCHR, '=', sizeof(char) * 13));
	printf("Mine : %s \n",(char *)ft_memchr(MEMCHR, '=', sizeof(char) * 14));
	printf("Real : %s \n\n",(char *)memchr(MEMCHR, '=', sizeof(char) * 14));
	printf("Mine : %s \n",(char *)ft_memchr(MEMCHR, '=', sizeof(char) * 16));
	printf("Real : %s \n\n",(char *)memchr(MEMCHR, '=', sizeof(char) * 16));
	int tab1[7] = {-49, 49, 1, -1, 0, -2, 2};
	int tab2[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("Mine : %s\n", (char *)ft_memchr(tab1, -1, 7));
	printf("Real : %s\n\n\n", (char *)memchr(tab2, -1, 7));
	
	printf("FT_MEMCMP\n");
	
	printf("Mine : %d\n",ft_memcmp("QVGFDFS","LCLCLLCC", 50));
	printf("Real : %d\n\n",memcmp("QVGFDFS","LCLCLLCC", 50));
	printf("Mine : %d\n",ft_memcmp("12345","*************", 4));
	printf("Real : %d\n\n",memcmp("12345","*************", 4));
	printf("Mine : %d\n",ft_memcmp("12334556789","++++++", 0));
	printf("Real : %d\n\n",memcmp("12334556789","++++++", 0));
	printf("Mine : %d\n",ft_memcmp("abc\0\0\0\0", "abc\0def", 7));
	printf("Real : %d\n\n\n",memcmp("abc\0\0\0\0", "abc\0def", 7));

	printf("FT_STRNSTR\n");
	int	i = 0;
	while (i<15)
	{
		printf("%s (i = %d)\n",ft_strnstr("The quick brown dog jumps over the lazy fox","quick",i),i);
		printf("%s (i = %d)\n",strnstr("The quick brown dog jumps over the lazy fox","quick",i),i);
		printf("\n");
		i++;
	}
	printf("%s\n\n",strnstr("lorem ipsum dolor sit amet", "", 10));
	
	printf("FT_STRTRIM\n");

	printf("%s\n",ft_strtrim("/*-/*-/*--|abc--/*Coucou|-**---*//*-/-","*-/"));
	printf("%s\n",ft_strtrim("--=--==-f----f--===--","*=-"));
	printf("%s\n",ft_strtrim("123456789","123456789"));
	printf("%s\n",ft_strtrim("osopdf[asofp]",""));
	printf("\n%s\n",ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet"," "));
	printf("%s \n\n",ft_strtrim(" lorem ipsum dolor sit amet","l "));


	int fd = open("coucou.txt",O_WRONLY);
	ft_putchar_fd('a',fd);
	ft_putchar_fd('\n',fd);
	ft_putstr_fd("Coucou\n",fd);
	ft_putendl_fd("Coucou sans retour a la ligne",fd);
	ft_putnbr_fd(42,fd);

	printf("FT_SPLIT\n");

	char **split = ft_split("xxxxxxxxhello!",'x');
	i = 0;
	printf("split = xxxxxxxxhello!  set = x\n\n");
	while (split[i])
		printf("%s\n",split[i++]);


	printf("FT_STRCHR\n");
	
	printf("Mine : %s\n",ft_strchr("teste", 'e'));
	printf("Real : %s\n\n",strchr("teste", 'e'));
	printf("Mine : %s\n",ft_strchr("teste", '\0'));
	printf("Real : %s\n\n",strchr("teste", '\0'));
	
/*LST*/

	// t_list *lst = ft_lstnew("Toto");

	// ft_lstadd_front (&lst, ft_lstnew("Tutu"));
	// ft_lstadd_front (&lst, ft_lstnew("Lili"));
	// ft_lstadd_back(&lst, ft_lstnew("Lulu"));
	// ft_print_list (&lst);
	// printf("\nTaille de la chaine : %d\n", ft_lstsize(lst));
	// printf("Derniere node de la liste : %s\n",(char *)ft_lstlast(lst)->content);

/*STRLCAT*/

	char str1[50] = "123456789";
	char str3[50] = "123456789";
	int a = ft_strlcat(str1,"123456789",0);
	int b = strlcat(str3,"123456789",0);
	printf("Mine str : %s .... Mine return : %d \n",str1,a);
	printf("Real str : %s .... Real return : %d \n",str3,b);

	char str5[50] = "123456";
	char str6[] = "********";
	char str7[50] = "123456";
	char str8[] = "********";
	int c = ft_strlcat(str5,str6,0);
	int d = strlcat(str7,str8,0);
	printf("Mine str : %s .... Mine return : %d \n",str5,c);
	printf("Real str : %s .... Real return : %d \n",str7,d);

	char dest[16] = "aaaaaa";
	memset(dest,'b',15);
    printf("%zu\n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
    write(1, "\n", 1);
    printf("%s",dest);

	printf("STRNCMP\n");

		char string1[] = "The quick brown dog jumps over the lazy fox";
		char string2[] = "The QUICK brown fox jumps over the lazy dog";
		printf("%d\n", ft_strncmp(string1,string2,13));
		printf("%d\n", strncmp(string1,string2,13));
		printf("\n");

		printf("%d\n", ft_strncmp(string1,string2,2));
		printf("%d\n", strncmp(string1,string2,2));
		printf("\n");

		printf("%d\n", ft_strncmp("test\200", "test\0", 6));
		printf("%d\n", strncmp("test\200", "test\0", 6));
		printf("\n");

}
