/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:51:22 by picarlie          #+#    #+#             */
/*   Updated: 2024/04/24 19:14:27 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	MANDELBROT
	z = z^2 + c
	z0 = (0,0)
	c is the actual point (eg we want to see if (0,1) is in the set)

	JULIA (oooooh, Julia !)
	./fractol julia <real> <imaginary>
	z = pixel_point + constant (is cst = r + i in the args)
	
	Burning ship
	zn+1 = (|r| + |i|)^2 + c	z0 = (0,0)

	Julia sets :
	c = 0.285 + 0i
	c = 0.285 + 0.01i
	c = −0.70176 − 0.3842i
	c = −0.8 + 0.156i
	vc = −0.7269 + 0.1889i
	c = 0.35 + 0.35i

*/
/*Put a pixel in the img buffer*/
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

/*static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	char	*dst;

	dst = img->pixels_ptr + (y * img->line_len + x
			* (img->bpp / 8));
	*(unsigned int *)dst = color;
}*/

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

/*
	Additive zoom doesnt work because it will flip the image,
		multiplicative zoom needed
	Multiplicative zoom scales with the scale ie zoom gets tinier
		when the scale is tiny
	How many times you want to iterate z^2+c to check if the point escapes
	If value escaped
	Hypotenuse > 2 => value escaped
	We are in the madelbrot fractal
*/
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
