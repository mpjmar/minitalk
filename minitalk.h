/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazjimenez <maria-j2@student.42malaga.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:26:30 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/21 18:55:05 by mpazjimenez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <errno.h> // used to handle system errors, such as those returned by kill()
# include "libft/libft.h"

// client
int	send_signal(pid_t pid, unsigned char octet);

// server
void	signal_handler(int signum);
#endif