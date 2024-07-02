/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:52:46 by astoll            #+#    #+#             */
/*   Updated: 2024/06/14 09:17:57 by astoll           ###   ########.fr       */
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
	struct sigaction	sa;
	pid_t				pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Erreur, essayez avec : ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_handler = receive_convert;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
