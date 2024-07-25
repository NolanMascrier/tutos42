/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 02:46:51 by nmascrie          #+#    #+#             */
/*   Updated: 2024/03/09 02:46:54 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copie;

	copie = NULL;
	i = ft_strlen(s);
	copie = (char *) malloc((i + 1) * sizeof(char));
	if (!copie)
		return (NULL);
	ft_strcpy(copie, s);
	return (copie);
}

void	ft_bzero(void *s, size_t n)
{
	char	*cast;

	cast = (char *)s;
	while (n > 0)
	{
		*cast = 0;
		cast++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (size >= SIZE_MAX || nmemb > SIZE_MAX)
		return (NULL);
	if ((nmemb * size) > SIZE_MAX)
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}

void    free_memory(t_hero *h)
{
    if (!h)
        return ;
    if (h->name)
        free(h->name);
    if (h->next)
        free_memory(h->next);
    free(h);
}

int     is_big(int a)
{
    return (a >= 400);
}