/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:49:30 by ylisyak           #+#    #+#             */
/*   Updated: 2018/10/10 23:01:36 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

SDL_Surface			*ft_get_img(char *path)
{
	SDL_Surface		*optimized;
	SDL_Surface		*tmp;
	SDL_PixelFormat	sdl_format;

	sdl_format.BitsPerPixel = 32;
	sdl_format.BytesPerPixel = 4;
	sdl_format.palette = NULL;
	sdl_format.Rmask = 0;
	sdl_format.Gmask = 0;
	sdl_format.Bmask = 0;
	sdl_format.Amask = 0;
	tmp = NULL;
	optimized = NULL;
	if ((tmp = IMG_Load(path)) != NULL)
		optimized = SDL_ConvertSurface(tmp, &sdl_format, 0);
	SDL_FreeSurface(tmp);
	return (optimized);
}

void				ft_fill_array_of_textures(t_textures *texture)
{
	int				itertmp;

	itertmp = texture->quantity;
	while (itertmp--)
	{
		texture->ptr_texture[itertmp] = \
		ft_get_img(texture->names_with_path[itertmp]);
		ft_putchar('\n');
		ft_putstr("Images uploads:");
		ft_putchar('\n');
		ft_putstr(texture->names_with_path[itertmp]);
	}
}

void				ft_error_malloc(t_win *c_cl)
{
	if (c_cl->main.quantity < 1)
		ft_error_textures("main", "imgs/main_elements");
	if (c_cl->main.ttf_quantity < 1)
		ft_error_textures("ttf", "fonts/");
	if (c_cl->menu.quantity < 1)
		ft_error_textures("manu", "imgs/main_elements");
	if (c_cl->walls.quantity < 4)
		ft_error_textures("walls", "imgs/walls");
	if (c_cl->flats.quantity < 1)
		ft_error_textures("flats", "imgs/flats");
	if (c_cl->ceiling.quantity < 1)
		ft_error_textures("ceiling", "imgs/ceiling");
	if (c_cl->nfpresent != 7)
		ft_error_folder();
}

void				ft_malloc_surfaces(t_win *c_cl)
{
	c_cl->main.quantity = ft_count_files("./imgs/main_elements/", c_cl);
	c_cl->main.ttf_quantity = ft_count_files("./fonts/", c_cl);
	c_cl->menu.quantity = ft_count_files("./imgs/menu_elements/", c_cl);
	c_cl->walls.quantity = ft_count_files("./imgs/walls/", c_cl);
	c_cl->walls.ptr_texture = malloc(sizeof(SDL_Surface) *\
	c_cl->walls.quantity);
	ft_fill_array_of_textures(&c_cl->walls);
	c_cl->flats.quantity = ft_count_files("./imgs/flats/", c_cl);
	c_cl->flats.ptr_texture = malloc(sizeof(SDL_Surface) *\
	c_cl->flats.quantity);
	ft_fill_array_of_textures(&c_cl->flats);
	c_cl->ceiling.quantity = ft_count_files("./imgs/ceiling/", c_cl);
	c_cl->ceiling.ptr_texture = malloc(sizeof(SDL_Surface) *\
	c_cl->ceiling.quantity);
	ft_fill_array_of_textures(&c_cl->ceiling);
	ft_error_malloc(c_cl);
}

int					ft_init_images(t_win *c_cl)
{
	int imgflags;

	imgflags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (!(IMG_Init(imgflags) & imgflags))
		ft_truble_img("SDL_image could not initialize! SDL_image Error: ",\
c_cl);
	if (!(c_cl->statement & FT_FALSE))
		ft_malloc_surfaces(c_cl);
	return (1);
}
