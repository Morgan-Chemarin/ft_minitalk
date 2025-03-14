/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:30 by dev               #+#    #+#             */
/*   Updated: 2025/03/14 00:57:24 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*stock_message(char *message, int ascii)
{
	int			i;
	char		*temp;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(message) + 2));
	if (!temp)
		return (NULL);
	while (message[i])
	{
		temp[i] = message[i];
		i++;
	}
	temp[i] = ascii;
	i++;
	temp[i] = '\0';
	free(message);
	return (temp);
}

void	update_buffer(char **buffer, char received_char)
{
	if (received_char == '\n')
	{
		ft_printf("%s\n", *buffer);
		free(*buffer);
		*buffer = ft_strdup("");
	}
	else
		*buffer = stock_message(*buffer, received_char);
}

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	bit_pos = 0;
	static char	received_char = 0;
	static char	*buffer = NULL;

	(void)context;
	if (buffer == NULL)
		buffer = ft_strdup("");
	if (signal == SIGUSR1)
		received_char = received_char << 1;
	else if (signal == SIGUSR2)
		received_char = (received_char << 1) | 1;
	bit_pos++;
	if (bit_pos == 8)
	{
		update_buffer(&buffer, received_char);
		bit_pos = 0;
		received_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID's server : %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
