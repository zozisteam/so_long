/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:45 by alalmazr          #+#    #+#             */
/*   Updated: 2022/04/07 00:51:19 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int	main(void)
{
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
}