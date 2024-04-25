/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:16:26 by picarlie          #+#    #+#             */
/*   Updated: 2024/04/24 19:26:23 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	To run when ESC or X button
	int (*f)(void *param)
*/
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

/*
	Keypress prototype
	int (*f)(int keycode, void *param)
	Difference between keycode (hardware, physical keyborad) and
	keysym (the symbol or function)
	XK_plus doesnt work
*/

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.10 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.10 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.10 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.10 * fractal->zoom);
	else if (keysym == 61 || keysym == 65451)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus || keysym == 65453)
	{
		fractal->iterations_definition -= 10;
		if (fractal->iterations_definition < 0)
			fractal->iterations_definition = 0;
	}
	fractal_render(fractal);
	return (0);
}

/*
	int (*f)(int button, int x, int y, void *param)
	Button5 zoom in
	Button4 zoom out
*/
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}
	(void)x;
	(void)y;
	fractal_render(fractal);
	return (0);
}

/*
	Track the mouse to change JULIA dynamically
	int (*f)(int x, int y, void *param)
*/

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
