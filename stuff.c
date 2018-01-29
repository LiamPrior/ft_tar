/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 23:00:51 by lprior            #+#    #+#             */
/*   Updated: 2018/01/28 23:01:23 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

void	perms(int *i, char *header, long int st_mode)
{
	char	*perm;
	int		x;

	x = 0;
	printf("perm: i = %d\n", *i);
	while (*i < 103)
		header[(*i)++] = '0';
	perm = convert_octal(st_mode);
	while (perm[x] != '\0')
		x++;
	header[106] = ' ';
	header[105] = perm[--x];
	header[104] = perm[--x];
	header[103] = perm[--x];
	while (*i < 108)
		(*i)++;
}

void	IDs(int *i, char *header, struct stat *info)
{
	printf("HI IDs: user id: i = %d\n", *i);
	char	*uid;
	char	*gid;
	int		x;

	uid = convert_octal(info->st_uid);
	x = strlen(uid);
	while (x++ < 6)
		header[(*i)++] = '0';
	while (*uid)
		header[(*i)++] = *(uid++);
	header[(*i)++] = ' ';
	(*i)++;

	printf("gr id: i = %d\n", *i);
	gid = convert_octal(info->st_gid);
	x = strlen(gid);
	while (x++ < 6)
		header[(*i)++] = '0';
	while (*gid)
		header[(*i)++] = *(gid++);
	header[(*i)++] = ' ';
	(*i)++;
}

void	size(int *i, char *header, struct stat *info)
{
	char	*size;
	int		x;
	printf("size: i = %d size = %llu\n", *i, info->st_size);
	size = convert_octal(info->st_size);
	if (S_ISDIR(info->st_mode))
	{
		x = 0;
		while (x++ < 11)
			header[(*i)++] = '0';
	}
	else
	{
		x = strlen(size);
		while (x++ < 11)
			header[(*i)++] = '0';
		while (*size)
			header[(*i)++] = *(size++);
	}
	header[(*i)++] = ' ';
}	
void	time(int *i, char *header, long int mod_time)
{
	char	*time;
	int		x;

	printf("time: i = %d\n", *i);
	time = convert_octal(mod_time);
	x = strlen(time);
	while (x++ < 11)
		header[(*i)++] = '0';
	while (*time)
		header[(*i)++] = *(time++);
	header[(*i)++] = ' ';
}

void	checksum_type(int *i, char *header, struct stat *info, char *path)
{
	printf("checksum id: i = %d\n", *i);
	while (*i < 154)					//checksum
		header[(*i)++] = ' ';
	(*i)++;
	header[(*i)++] = ' ';

	printf("typeflag: i = %d\n", *i);
	header[(*i)++] = typeflag(path, (long int)info->st_mode);	//here is typeflag
}
