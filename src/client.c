/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:26 by dev               #+#    #+#             */
/*   Updated: 2025/03/12 16:45:19 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

volatile sig_atomic_t	g_signal_received = 0;

void	ack_handler(int signal)
{
	(void)signal;
	g_signal_received = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_signal_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		while (!g_signal_received)
			;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("Error: %s <PID> <Message>\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, ack_handler);
	i = 0;
	while (av[2][i] != '\0')
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\n');
	return (0);
}
