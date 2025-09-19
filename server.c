/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:47:24 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/19 19:18:30 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// if SIGUSR1-> bit 0
// if SIGUSR2-> bit 1

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	
	while (1)
		pause();
	
	return EXIT_SUCCESS;
}

void	signal_handler(int signum)
{
	
	
}
