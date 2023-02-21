/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecanci <ecanci@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:35:02 by ecanci            #+#    #+#             */
/*   Updated: 2023/02/22 00:35:08 by ecanci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_bit_editing(int x)
{
    static int bit = 7;
    static int setup = 0;
    
    setup += (x << bit);
    if (bit == 0)
    {
        ft_printf("%c", setup);
        bit = 7;
        setup = 0;
    }
    else
        bit--;
}

void ft_signal_catch(int x)
{
    if (x == SIGUSR1)
        ft_bit_editing(1);
    else
        ft_bit_editing(0);
}

int main()
{
    int pid;

    pid = getpid();
    ft_printf("pid: %u", pid);
    signal(SIGUSR1, ft_signal_catch);
    signal(SIGUSR2, ft_signal_catch);
    while (1)
        pause();

}
