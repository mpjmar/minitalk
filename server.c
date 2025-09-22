/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:47:24 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/22 16:53:48 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// if SIGUSR1-> bit 0
// if SIGUSR2-> bit 1

int	main(void)
{
	struct sigaction	sa;
	
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	// sigaddset(&sa.sa_mask, SIGUSR1);
	// sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Failed to set up signal handlers.\n");
		return (EXIT_FAILURE);
	}
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

void	signal_handler(int signum)
{
	static unsigned char	char_in_progress = 0;
	static int				bit_counter = 0;

	char_in_progress <<= 1;
	if (signum == SIGUSR2)
		char_in_progress |= 1;
	bit_counter++;
	if (bit_counter == 8)
	{
		if (char_in_progress == '\0')
		{
			write (1, "\n", 1);
			// ft_printf("\nMessage complete!\n");
			// char_in_progress = 0;
			// bit_counter = 0;
			//return ;
		}
		else
			write (1, &char_in_progress, 1);
		char_in_progress = 0;
		bit_counter = 0;
	}
}
