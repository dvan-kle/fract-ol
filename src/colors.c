/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 16:35:06 by dvan-kle      #+#    #+#                 */
/*   Updated: 2023/06/06 13:34:20 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"



int	ft_coloring2(int iterations)
{
	double	t;
	int 	r;
	int 	g;
	int		b;
	int 	color;

	t = (double)iterations / (double)MAX_ITERATIONS;
	r = (int)(19.2 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color = r * 0x10000 + g * 0x100 + b + 25;
	//printf("COLOR: %i\n", color);
	return (color);
}

// hsv = [powf((iterations / max) * 360, 1.5) % 360, 100, (i / max) * 100]

t_hsv iterations_to_hsv(int iterations)
{
	double	calc;
	t_hsv	hsv;
	
	//printf("ITERATIONS: %i\n", iterations);
	calc = pow((((double)iterations / (double)MAX_ITERATIONS) * (double)1200), 1.5);
	//printf("calc: %f\n", calc);
	hsv.h = (int)calc % 360;
	hsv.s = 100;
	hsv.v = ((double)iterations / (double)MAX_ITERATIONS) * 100;
	//printf("H value: %f, S value: %f, V value: %f\n", hsv.h, hsv.s, hsv.v);
	return (hsv);
}

t_hsv iterations_to_hsv2(int iterations)
{
	double	calc;
	t_hsv	hsv;
	
	//printf("ITERATIONS: %i\n", iterations);
	//calc = pow((((double)iterations / (double)MAX_ITERATIONS) * (double)360), 1.5);
	//printf("calc: %f\n", calc);
	hsv.h = ((double)255 * (double)iterations / (double)MAX_ITERATIONS);
	hsv.s = 255;
	hsv.v = 255;
	//printf("H value: %f, S value: %f, V value: %f\n", hsv.h, hsv.s, hsv.v);
	return (hsv);
}

t_rgb hsv_to_rgb(t_hsv hsv) 
{
	double r = 0, g = 0, b = 0;
	t_rgb rgb;

	if (hsv.s == 0)
	{
		r = hsv.v;
		g = hsv.v;
		b = hsv.v;
	}
	else
	{
		
		int i;
		double f, p, q, t;
		//printf("H value: %f, S value: %f, V value: %f\n", hsv.h, hsv.s, hsv.v);
		if (hsv.h == 360)
			hsv.h = 0;
		else
			hsv.h = hsv.h / 60;


		//printf("%f\n", hsv.h);
		i = (int)trunc(hsv.h);
		//printf("%i\n", i);
		f = hsv.h - i;

		p = hsv.v * (1.0 - hsv.s);
		q = hsv.v * (1.0 - (hsv.s * f));
		t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));

		switch (i)
		{
		case 0:
			r = hsv.v;
			g = t;
			b = p;
			break;

		case 1:
			r = q;
			g = hsv.v;
			b = p;
			break;

		case 2:
			r = p;
			g = hsv.v;
			b = t;
			break;

		case 3:
			r = p;
			g = q;
			b = hsv.v;
			break;

		case 4:
			r = t;
			g = p;
			b = hsv.v;
			break;

		default:
			r = hsv.v;
			g = p;
			b = q;
			break;
		}

	}

	rgb.r = r * 255;
	rgb.g = g * 255;
	rgb.b = b * 255;

	return rgb;
}

int convert_to_hex(t_rgb rgb)
{
	int r;
	int g;
	int b;
	int a;

	r = rgb.r;
	g = rgb.g;
	b = rgb.b;
	a = 255;
	
	return (r << 24 | g << 16 | b << 8 | a);
}

int hue_saturation(int iterations)
{
	int r;
	int g;
	int b;
	int a;

	r = 255 * (double)iterations / (double)MAX_ITERATIONS;
	g = 255;
	b = 255;
	if (iterations > MAX_ITERATIONS)
		a = 0;
	else
		a = 255;
	
	return (r << 24 | g << 16 | b << 8 | a);
}

int colors(int iterations)
{
	int color;

	//color = convert_to_hex(hsv_to_rgb(iterations_to_hsv2(iterations)));
	color = hue_saturation(iterations);
	//printf("LOADING.... %i%%\n", iterations);
	return (color);
}
