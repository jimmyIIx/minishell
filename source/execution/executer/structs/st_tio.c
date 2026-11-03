/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_tio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:56:14 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/24 16:15:05 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_tio_clear(t_tio *tio)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &tio->old);
}

void	st_tio_init(t_tio *tio)
{
	tcgetattr(STDIN_FILENO, &tio->old);
	ft_memcpy(&tio->new, &tio->old, sizeof(struct termios));
	tio->new.c_cc[VQUIT] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &tio->new);
}
