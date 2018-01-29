/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:50:19 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/28 20:55:39 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

int		typeflag(char *path, long int st_mode)
{
	if (S_ISREG(st_mode) == 1)
		return (0 + 48);
	else if (S_ISLNK(st_mode) == 1)
		return (2 + 48);
	else if (S_ISCHR(st_mode) == 1)
		return (3 + 48);
	else if (S_ISBLK(st_mode) == 1)
		return (4 + 48);
	else if (S_ISDIR(st_mode) == 1)
		return (5 + 48);
	else if (S_ISFIFO(st_mode) == 1)
		return (6 + 48);
	else
		return (7 + 48);
	return (0 + 48);
}

char	*find_link(char *path, char *header, int *i)
{
	char	*buff;
	int		x;

	buff = (char *)malloc(100);
	x = 0;
	if (readlink(path, buff, 100) == -1)
		return ("\0");
	if (strlen(buff) > 100)
	{
		printf("ft_archive: %s: Link contents too long\n", path);
		return (NULL);
	}
	return (buff);
}

char	*checksum(char *header, int *i)
{
	int	checksum;
	int index;

	checksum = 0;
	index = 0;
	while (index < 512)
		checksum += header[index++];
	return (convert_octal((long long int)checksum + 32));
}
