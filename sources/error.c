/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:28:17 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/08 17:19:27 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(char *detail, char *str, int code)
{
	ft_putstr_fd("Error\n", 2);
	if (detail)
		ft_putstr_fd(detail, 2);
	if (detail && str)
		ft_putstr_fd(": ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (code);
}

int	err_msg_val(int detail, char *str, int code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putnbr_fd(detail, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (code);
}
