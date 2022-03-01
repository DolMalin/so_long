/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:12:26 by pdal-mol          #+#    #+#             */
/*   Updated: 2021/12/17 16:02:53 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	size_t	i;
	char	*copy_str;

	i = 0;
	copy_str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!copy_str || !src)
		return (NULL);
	while (src[i] && i < (size_t)n)
	{
		copy_str[i] = src[i];
		i++;
	}
	copy_str[i] = '\0';
	return (copy_str);
}
