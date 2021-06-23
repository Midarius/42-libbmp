/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbmp_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 10:56:48 by fcals             #+#    #+#             */
/*   Updated: 2020/01/03 11:01:47 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBMP_DEF_H
# define LIBBMP_DEF_H

# define BM_MAGIC 0x4d42

typedef struct			s_bmp_info {
	unsigned short		type;
	unsigned int		file_size;
	unsigned short		reserved1;
	unsigned short		reserved2;
	unsigned int		offset;
}						t_bmp_info;

typedef struct			s_info_header {
	unsigned int		size;
	unsigned int		width;
	unsigned int		height;
	unsigned short		planes;
	unsigned short		bit_count;
	unsigned int		compression;
	unsigned int		size_image;
	unsigned int		x_pixel_meter;
	unsigned int		y_pixel_meter;
	unsigned int		color_used;
	unsigned int		color_important;
	unsigned char		*unused;
}						t_info_header;

typedef struct			s_rgb_color {
	unsigned char		blue;
	unsigned char		green;
	unsigned char		red;
	unsigned char		reserved;
}						t_rgb_color;

typedef struct			s_bmp_data_rgba {
	unsigned char		blue;
	unsigned char		green;
	unsigned char		red;
	unsigned char		alpha;
}						t_bmp_data_rgba;

typedef struct			s_bmp_data_palette {
	unsigned char		data;
	t_rgb_color			*color;
}						t_bmp_data_palette;

typedef struct			s_bmp {
	t_bmp_info			image_info;
	t_info_header		image_header;
	t_rgb_color			*palette;
	t_bmp_data_palette	*data_palette;
	t_bmp_data_rgba		*data_rgb;
}						t_bmp;

#endif
