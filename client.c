/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:26:08 by maria-j2          #+#    #+#             */
/*   Updated: 2025/10/01 17:39:04 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Global flag used for synchronization between the signal handler and 
// the main program.

volatile sig_atomic_t	g_ack = 0;

int	main(int argc, char **argv)
{
	int	success;
	int	pid;
	int	i;

	signal(SIGUSR1, ack_handler);
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			success = send_signal(pid, argv[2][i]);
			if (success == -1)
			{
				ft_printf("Error sending signal");
				return (1);
			}
			i++;
		}
		send_signal(pid, '\0');
	}
	return (EXIT_SUCCESS);
}

void	ack_handler(int signum)
{
	(void)signum;
	g_ack = 1;
}

// if SIGUSR1-> bit 0
// if SIGUSR2-> bit 1

int	send_signal(pid_t pid, unsigned char octet)
{
	int	i;
	int	success;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		if (octet & (1 << i))
			success = kill(pid, SIGUSR2);
		else
			success = kill(pid, SIGUSR1);
		if (success == -1)
			return (-1);
		while (!g_ack)
			pause();
		i--;
	}
	return (success);
}
