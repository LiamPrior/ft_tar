/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 23:02:47 by lprior            #+#    #+#             */
/*   Updated: 2018/01/28 23:02:57 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

void	link_name(int *i, char *header, char *path)
{
	char 	*link;
	char 	x;
	printf("linkname: i = %d\n", *i);
	if (header[(*i) - 1] == 50)
	{
		x = 0;
		char *link = find_link(path, header, i);
		printf("INSIDE IF LINK\n");
		while (link[x] != '\0')
			header[(*i)++] = link[x++];
		while (*i < 257)
			(*i)++;
	}
	else
	{
		while (*i < 257)
			(*i)++;
	}
}

void	magic(int *i, char *header)
{
	printf("magic: i = %d\n", *i);
	header[(*i)++] = 'u';				//magic ustar id
	header[(*i)++] = 's';
	header[(*i)++] = 't';
	header[(*i)++] = 'a';
	header[(*i)++] = 'r';
	(*i)++;
	header[(*i)++] = '0';
	header[(*i)++] = '0';
}
void	user_name(int *i, char *header, struct stat *info)
{
	struct	group *grp;
	struct	passwd *pwd;
	int		x;

	x = 0;
	printf("user name: i = %d\n", *i);
	pwd = getpwuid(info->st_uid);	//user name
	while (pwd->pw_name[x] != '\0')
		header[(*i)++] = pwd->pw_name[x++];
	
	while (x++ < 32)
		(*i)++;
	printf("group name: i = %d\n", *i);
	x = 0;
	grp = getgrgid(info->st_gid);	//group name
	while (grp->gr_name[x])
		header[(*i)++] = grp->gr_name[x++];
	while (x++ < 32)
		(*i)++;
}
void	devs(int *i, char *header, struct stat *info)
{
	char	*octal_major;
	char	*octal_minor;
	int		x;

	printf("dev major : i = %d\n", *i);
	octal_major = convert_octal((long long int)major(info->st_rdev));
	octal_minor = convert_octal((long long int)minor(info->st_rdev));
	x = strlen(octal_major);					//devmajor
	while (x++ < 6)
		header[(*i)++] = '0';
	while (*octal_major)
		header[(*i)++] = *(octal_major++);
	header[(*i)++] = ' ';
	(*i)++;

	printf("dev minor: i = %d\n", *i);
	x = strlen(octal_minor);					//devminor
	while (x++ < 6)
		header[(*i)++] = '0';
	while (*octal_minor)
		header[(*i)++] = *(octal_minor++);
	header[(*i)++] = ' ';
	(*i)++;
	printf("prefix: i = %d\n", *i);
}

char	*check_sum(int *i, char *header)
{
	int x;
	char *res;

	*i = 148;
	res = checksum(header, i);
	x = strlen(res);
	while (x++ < 6)
		header[(*i)++] = '0';
	while (*res)
		header[(*i)++] = *(res++);
	return (header);
}
