/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecanci <ecanci@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:34:33 by ecanci            #+#    #+#             */
/*   Updated: 2023/02/22 00:34:39 by ecanci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int atoi(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (str[i++])
        res = (str[i] - '0') + (res * 10);
    return (res);
}

void ft_bit_shift(int pid, char *str)
{
    int i;
    unsigned char x;

    while (*str)
    {
        i = 8;
        x = *str++;
        while (i--)
        {
            if ((x >> i) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(100);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        ft_printf("Try Again! Just enter two arguments.");
        return (0);
    }
    ft_bit_shift(ft_atoi(av[1]), av[2]);
}
