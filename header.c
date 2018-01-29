/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:40:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/28 23:36:14 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

void	name(int *i, char *header, struct stat *info, char *path)
{
	if (strlen(path) > 100)
	{
		printf("ft_archive: %s: Pathname too long\n", path);
		return ;
	}
	while (*i < 100 && path[*i] != '\0')
	{
		header[*i] = path[*i];
		(*i)++;
	}
	if (S_ISDIR(info->st_mode))
		header[(*i)++] = '/';
	while (*i < 100)
		(*i)++;
}

char	*create_header(struct stat *info, char *path)
{
	char	*header;
	int		i;
	
	i = 0;
	header = (char *)malloc(sizeof(char) * 512);
	ft_memset(header, '\0', 512);
	printf("name: i = %d\n", i);
	name(&i, header, info, path);
	perms(&i, header, (long int)info->st_mode);
	IDs(&i, header, info);
	size(&i, header, info);
	time(&i, header, (long int)info->st_mtime);
	checksum_type(&i, header, info, path);
	link_name(&i, header, path);
	magic(&i, header);
	user_name(&i, header, info);
	devs(&i, header, info);
	return (check_sum(&i, header));
}


