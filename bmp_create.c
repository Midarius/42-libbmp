/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:51:13 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 10:51:35 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bmp	*bmp_create(unsigned int width, unsigned int height, unsigned int mode)
{
	t_bmp	*bmp;

	if (!(bmp = (t_bmp*)malloc(sizeof(t_bmp))))
		return (NULL);
	bmp_init_header(bmp);
	bmp_init_bip(bmp);
}
