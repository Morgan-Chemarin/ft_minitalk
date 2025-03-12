/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:30 by dev               #+#    #+#             */
/*   Updated: 2025/03/12 12:19:22 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signal)
{
	static int	bit_pos = 0;
	static char	received_char = 0;

	if (signal == SIGUSR1)
		received_char = received_char << 1;
	else if (signal == SIGUSR2)
		received_char = (received_char << 1) | 1;
	bit_pos++;
	if (bit_pos == 8)
	{
		write(1, &received_char, 1);
		bit_pos = 0;
		received_char = 0;
	}
}

int	main(void)
{
	ft_printf("PID du serveur : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
