/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:54:24 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/03 15:14:18 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// code as hell!!!
int	main(int argc, char **argv)
{
	int		fd;
	char	*gnl;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		gnl = get_next_line(fd);
		ft_printf("%s", gnl);
		while (gnl)
		{
			gnl = get_next_line(fd);
			if (!gnl)
			{
				free(gnl);
				break ;
			}
			ft_printf("%s", gnl);
			if (gnl)
				free(gnl);
		}
		close(fd);
	}
	return (EXIT_SUCCESS);
}