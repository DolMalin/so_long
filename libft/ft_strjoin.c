/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:27:39 by pdal-mol          #+#    #+#             */
/*   Updated: 2021/12/15 13:12:05 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*output;
	size_t	len;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	while (str1[++i])
		output[i] = str1[i];
	while (str2[++j])
		output[i + j] = str2[j];
	output[len] = '\0';
	return (output);
}
