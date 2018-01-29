/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 21:10:02 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/28 21:10:06 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_tar.h"

int		create_arch(char *str, char *name)
{
	FILE	*file_ptr;
	int		i;
	
	i = 0;
	file_ptr = fopen(name, "w+");
	while (i < 512 * 3)
	{
		if (str[i] == '\0')
			write(1, "\0", 2);
		write(1, &(str[i++]), 1);
	}
	fwrite(str, 1, 512 * 3, file_ptr);
	fclose(file_ptr);
	return (0);
}
