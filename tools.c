/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:40:44 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/28 21:03:16 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

char	*convert_octal(long long int nb)
{
	char		*print;
	long int	i;

	i = 0;
	print = ft_memalloc(22);
	if (nb == 0)
		print[i++] = '0';
	while (nb != 0)
	{
		print[i++] = (nb % 8) + 48;
		nb /= 8;
	}
	print[i] = '\0';
	return (ft_strrev(print));
}

char	*create_path(char *s1, char *s2)
{
	char		*path;
	int			i;
	static int	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	path = (char *)malloc(len);
	while (s1[i])
	{
		path[i] = s1[i];
		i++;
	}
	path[i++] = '/';
	while (*s2)
	{
		path[i] = *s2++;
		i++;
	}
	path[i] = '\0';
	return (path);
}

char	*remalloc(char *final, int old_blocks, int bytes)
{
	char	*new;
	int		i;

	i = 0;
	bytes *= 512;
	new = (char *)malloc(bytes);
	while (i < old_blocks * 512)
	{
		new[i] = final[i];
		i++;
	}
	while (i < bytes)
		new[i++] = '\0';
	free(final);
	return (new);
}
