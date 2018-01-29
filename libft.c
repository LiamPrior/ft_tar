/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:47:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/28 21:00:45 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = '\0';
}

void	*ft_memset(void *buffer, int c, size_t num)
{
	char	*tab;

	tab = (char *)buffer;
	while (num--)
		*tab++ = c;
	return (buffer);
}

void	*ft_memalloc(size_t size)
{
	void	*tab;

	if (!(tab = (void *)malloc(size)))
		return (NULL);
	ft_memset(tab, 0, size);
	return (tab);
}

char	*ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		x;

	x = 0;
	i = strlen(str);
	rev = (char *)malloc(sizeof(char) * (i + 1));
	while (--i > -1)
		rev[x++] = str[i];
	rev[x] = '\0';
	free(str);
	return (rev);
}

size_t	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
