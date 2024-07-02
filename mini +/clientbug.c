/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:48:03 by astoll            #+#    #+#             */
/*   Updated: 2024/05/22 14:58:34 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	convert_send(pid_t pid, char str, size_t len)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < len)
	{
		count = 0;
		while (count < 8)
		{
			if ((str & (0x01 << count)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(42);
			count++;
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;
	size_t	len;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		len = ft_strlen(str);
		while (*str != '\0')
		{
			convert_send(pid, *str, len);
			str++;
		}
		convert_send(pid, '\n', 1);
	}
	else
	{
		ft_printf("Error, try with : ./client PID MESSAGE\n");
	}
	return (0);
}
