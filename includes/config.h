/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 02:22:48 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 20:14:46 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "e_bool.h"
# include <SDL.h>

typedef struct	s_config
{
	Uint32		win_w;
	Uint32		win_h;
	double		half_w;
	double		half_h;
	double		ratio;

	enum e_bool	fullscreen;

	double		fov;
	double		half_fov;
	double		tan_half_fov;

	int			fps_max;

	double		mouse_sensi;

	enum e_bool	lights;
}				t_config;

t_config		load_config(void);
t_config		load_default_config(void);

#endif
