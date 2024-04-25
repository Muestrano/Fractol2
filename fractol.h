/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:06:23 by picarlie          #+#    #+#             */
/*   Updated: 2024/04/24 19:27:19 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include "Libft/libft.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

/*Colors*/
# define BLACK	0x000000 //RGB(0, 0, 0)
# define WHITE	0xFFFFFF //RGB(255, 255, 255)
# define RED	0xFF0000 //RGB(255, 0, 0)
# define GREEN	0x00FF00 //RGB(0, 255, 0)
# define BLUE	0x0000FF //RGB(0, 0, 255)

/*Pyshedelic colors*/
# define MAGENTA_BURST	0xFF00FF 
# define LIME_SHOCK	0xCCFF00
# define NEON_ORANGE	0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM	0x33CCCC
# define HOT_PINK	0xFF66B2
# define ELECTRIC_BLUE	0x0066FF
# define LAVA_RED	0xFF3300

/*Complex struct*/
typedef struct	s_complex
{
	double	x;
	double	y;
} t_complex;

/*Define image structure*/
typedef struct	s_img
{
	void	*img_ptr; //pointer to img struct
	char	*pixels_ptr; //points to the actual pixel
	int		bpp; //bits per pixel
	int		endian;
	int		line_len;
}	t_img;

/*Fractal ID
MLX stuff
Image
Hooks values*/
typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection; //from mlx_init()
	void	*mlx_window; //from mlx_new_window()

	t_img	img;

	//Hooks members variables // TODO
	double	escape_value;//hypotenuse
	int		iterations_definition; //value tight with the image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	
}	t_fractal;

/*Init functions*/

void	fractal_init(t_fractal *fractal);

/*Render*/

void	fractal_render(t_fractal *fractal);

/*Maths*/
double	map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

/*Hooks events*/
int	key_handler(int keysym, t_fractal *fractal);
int	close_handler(t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);
int	julia_track(int x, int y, t_fractal *fractal);
/*String utils*/
double	atodbl(char *s);

#endif



/*
free les ptrs quand mlx_destroy_window?
mlx_pixel_put a recoder*/