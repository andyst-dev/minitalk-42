/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serversignal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:49:06 by astoll            #+#    #+#             */
/*   Updated: 2024/06/13 10:56:20 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	receive_convert(int sig)
{
	static int	count;
	static int	chara;

	if (sig == SIGUSR1)
		chara |= (0x01 << count);
	count++;
	if (count == 8)
	{
		ft_printf("%c", chara);
		count = 0;
		chara = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error, try with : ./server\n");
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, receive_convert);
		signal(SIGUSR2, receive_convert);
		pause();
	}
	return (0);
}
