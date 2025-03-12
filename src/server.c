/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:30 by dev               #+#    #+#             */
/*   Updated: 2025/03/12 16:47:01 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	bit_pos = 0;
	static char	received_char = 0;
	static char	buffer[10024];
	static int	index = 0; 

	(void)context;
	if (signal == SIGUSR1)
		received_char = received_char << 1;
	else if (signal == SIGUSR2)
		received_char = (received_char << 1) | 1;

	bit_pos++;
	if (bit_pos == 8)
	{
		if (received_char == '\n')
		{
			buffer[index] = '\0';
			ft_printf("%s\n", buffer);
			index = 0;
		}
		else
		{
			buffer[index++] = received_char;
		}
		bit_pos = 0;
		received_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;

	ft_printf("PID du serveur : %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

