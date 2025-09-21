/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazjimenez <maria-j2@student.42malaga.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:26:08 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/21 15:15:54 by mpazjimenez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	success;
	int	pid;
	int	i;

	i = 0;
	if (argc == 3){
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			success = send_signal(pid, argv[2][i]);
			if (success == -1)
			{
				perror("Error sending signal");
				// if kill() fails, it returns errno to indicate the type or error
				return (errno);
			}
			i++;
		}
	}
	return EXIT_SUCCESS;
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
		if (octet & (1 << i))
		{
			success = kill(pid, SIGUSR2);
			usleep(100);
		}
		else
		{
			success = kill(pid, SIGUSR1);
			usleep(100);
		}
		i--;
	}
	return (success);
}
