/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:24:54 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/28 23:36:28 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

// int		ft_archive(char *path)
// {
// 	struct stat 	*info;
// 	struct dirent	*file;
// 	DIR				*directory;
// 	char			*final;
// 	char			*header;
	
// 	info = ft_memalloc(sizeof(struct stat));
// 	if (lstat(path, info) < 0)
// 	{
// 		printf("ft_archive: ma: Cannot stat: No such file or directory\n");
// 		return (-1);
// 	}
	
// 	if (header = create_header(info) == -1)
// 		remalloc(final, 1);
// 	else if (S_ISDIR(name) == 1)
// 	{
// 		directory = opendir(path);
// 		while (file = readdir(directory)) != NULL)
// 		{
// 			if (S_ISDIR(path) == 1)
// 				remalloc(final, 1);
// 			ft_archive(create_path(path, file->d_name)));
// 		}
// 	}
// 	else
// 	{
// 		remalloc(final, info->st_blocks + 1);
// 		file_content(path, final);
// 	}
// }


// int main(int ac, char **av)
// {
// 	int			i;

	
// 	i = 0;
	
// 	if (ac == 1)
// 		printf("ft_archive: Must specify one of -c -f\n");
// 	if (ac == 2)
// 		printf("ft_archive: no files or directories specified\n");
// 	if (ac == 3)
// 		printf("ft_archive: Cannot stat: No such file or directory\n");
	
// 	i = 3;
// 	while (av[i] != NULL)
// 		if (ft_archive(av[i++]) == -1)
// 			return (1);
// 	remalloc(final, 1);
	
// 	return (0);
// }

int main()
{
	struct stat 	*info;
	char	*final;
	int		blocks;
	
	final = (char *)malloc(512);
	blocks = 0;
	struct group *grp;
	struct passwd *pwd;
	
	pwd = getpwuid(info->st_uid);
	grp = getgrgid(info->st_gid);
	
	if (lstat("test.txt", info) < 0)
	{
		printf("ft_archive: ma: Cannot stat: No such file or directory\n");
		return (-1);
	}

	final = create_header(info, "test.txt");

	blocks++;
	int i;
	
	final = remalloc(final, blocks, blocks + 2);
	while (i < 512 * 3)
	{
		if (final[i] == '\0')
			write(1, "^@", 2);
		write(1, &(final[i++]), 1);
	}

	return 0;
	
}
