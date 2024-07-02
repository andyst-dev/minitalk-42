/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:48:03 by astoll            #+#    #+#             */
/*   Updated: 2024/06/14 09:18:27 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	convert_send(pid_t pid, char str)
{
	int		count;

	count = 0;
	while (count < 8)
	{
		if ((str & (0x01 << count)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (*str != '\0')
		{
			convert_send(pid, *str);
			str++;
		}
		convert_send(pid, '\n');
	}
	else
	{
		ft_printf("Erreur, essayez avec : ./client PID MESSAGE\n");
		return (1);
	}
	return (0);
}
