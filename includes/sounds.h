/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:20:32 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 20:18:20 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUNDS_H
# define SOUNDS_H

# include <SDL_mixer.h>

typedef struct	s_sounds
{
	Mix_Music	*lamerde;
	Mix_Chunk	*zap;
	Mix_Chunk	*fu_bitch;
	Mix_Chunk	*xplosion;
	Mix_Chunk	*mip_mep;
	Mix_Chunk	*meeeh;
	Mix_Chunk	*pew;
	Mix_Chunk	*slurp;
	Mix_Chunk	*yeee;
	Mix_Chunk	*mwiiicrkk;
}				t_sounds;

void			read_sounds_from_file(int fd, t_sounds **sounds);
void			write_sounds_to_file(int fd);
void			free_sounds(t_sounds *sounds);

#endif
