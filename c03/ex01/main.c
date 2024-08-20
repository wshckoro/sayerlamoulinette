/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:48:39 by fmartore          #+#    #+#             */
/*   Updated: 2024/08/20 17:47:36 by fmartore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:10:29 by fmartore          #+#    #+#             */
/*   Updated: 2024/08/20 15:47:20 by fmartore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~`[]{}';:\"?/>.<,\\|";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

int random_number(int min_num, int max_num)
    {
    int result = 0, low_num = 0, hi_num = 0;
	
	if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}


int	main(void)
{
	char	*str;
	char	*str2;
	int		i;
	int		n;
	FILE	*machine;
	FILE	*user;

	machine = fopen("original.output", "w");
	user = fopen("user.output", "w");
	srand(time(NULL));
	i = 0;
	str = malloc(101 * sizeof(char));
	str2 = malloc(101 * sizeof(char));
	fprintf(machine, "%d\n", strncmp("", "", 0));
	fprintf(user, "%d\n", ft_strncmp("", "", 0));
	fprintf(machine, "%d\n", strncmp("a", "a", 0));
	fprintf(user, "%d\n", ft_strncmp("a", "a", 0));
	while (i < 200)
	{
		rand_string(str, random_number(1, 100));
		strcpy(str2, str);
		if (i % 2 == 0)
			rand_string(str2, random_number(1, 100));
		n = random_number(1, 100);
		fprintf(machine, "%d\n", strncmp(str, str2, n));
		fprintf(user, "%d\n", ft_strncmp(str, str2, n));
		i++;
	}
}
