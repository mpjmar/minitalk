/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:26:30 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/27 18:26:57 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <errno.h> // used to handle system errors, such as those returned by kill()
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft/libft.h"

// client
void	ack_handler(int signum);
int		send_signal(pid_t pid, unsigned char octet);

// server
void	signal_handler(int signum, siginfo_t *info, void *context);

#endif