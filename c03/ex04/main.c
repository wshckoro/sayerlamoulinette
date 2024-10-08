/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:10:29 by fmartore          #+#    #+#             */
/*   Updated: 2024/08/20 17:49:37 by fmartore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

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
	char	*dest;
	char	*dest2;
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
	dest = malloc(202 * sizeof(char));
	dest2 = malloc(202 * sizeof(char));
	fprintf(machine, "%s\n", strstr("", ""));
	fprintf(user, "%s\n", ft_strstr("", ""));
	fprintf(machine, "%s\n", strstr("hellololeooh4224", "loo"));
	fprintf(user, "%s\n", ft_strstr("hellololeooh4224", "loo"));
	while (i < 200)
	{
		rand_string(str, random_number(1, 100));
		strcpy(str2, str);
		if (i % 3 == 0)
			rand_string(str2, random_number(1, 100));
		n = random_number(1, 100);
		fprintf(machine, "%s\n", strstr(str, str2));
		fprintf(user, "%s\n", ft_strstr(str, str2));
		dest[0] = '\0';
		dest2[0] = '\0';
		i++;
	}
	free(str);
	free(str2);
	free(dest);
	free(dest2);
}
