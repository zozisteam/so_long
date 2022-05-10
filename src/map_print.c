/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 06:42:03 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/07 05:09:35 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* print each tile depending on the char in map */
/* coordinates if 'P' or 'C' or 'E' and etc ... */
void	print_map(t_game *game)
{
	int		line;
	int		col;

	line = 0;
	while (line < game->map.line)
	{
		col = 0;
		while (col < game->map.column)
		{
			print_sprites(game, line, col);
			col++;
		}
		line++;
	}
}
