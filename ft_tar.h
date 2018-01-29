/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:41:07 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/28 23:04:09 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAR_H
# define FT_TAR_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <string.h>

char	*convert_octal(long long int nb);
char	*create_path(char *s1, char *s2);
char	*remalloc(char *final, int old_blocks, int bytes);
int		typeflag(char *path, long int st_mode);
char	*find_link(char *path, char *header, int *i);
char	*checksum(char *header, int *i);
char	*create_header(struct stat *info, char *path);
char	*ft_strrev(char *str);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *buffer, int c, size_t num);
size_t	ft_strlen(char *str);
void	perms(int *i, char *header, long int st_mode);
void	IDs(int *i, char *header, struct stat *info);
void	size(int *i, char *header, struct stat *info);
void	time(int *i, char *header, long int mod_time);
void	checksum_type(int *i, char *header, struct stat *info, char *path);
void	link_name(int *i, char *header, char *path);
void	magic(int *i, char *header);
void	user_name(int *i, char *header, struct stat *info);
void	devs(int *i, char *header, struct stat *info);
char	*check_sum(int *i, char *header);
int		create_arch(char *str, char *name);

#endif
