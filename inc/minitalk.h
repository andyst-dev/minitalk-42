/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:24:20 by astoll            #+#    #+#             */
/*   Updated: 2024/05/22 14:24:56 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);

#endif