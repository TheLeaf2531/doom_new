/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:13:46 by vboissel          #+#    #+#             */
/*   Updated: 2019/05/01 20:59:48 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "sectors.h"

typedef struct			s_hud
{
	SDL_Surface			*sun;
	SDL_Surface			*moon;
	SDL_Surface			*cross[3];
	int					id;
	SDL_Surface			*bullet;
	SDL_Surface			*happy_face;
	SDL_Surface			*meh_face;
	SDL_Surface			*sad_face;
	SDL_Surface			*dead_face;
	SDL_Surface			*badass_face;
	SDL_Surface			*sehr_happy_face;
	SDL_Surface			*hurt_face;
}						t_hud;

typedef struct			s_map
{
	t_sectors			*sectors;
	t_coords			spawn;
	int					player_spawn_index;
	SDL_Surface			*daysky;
	SDL_Surface			*nightsky;
	enum e_bool			daytime;
	t_hud				hud;
	SDL_Surface			*melee_sprite;
	SDL_Surface			*book_sprites[5];
	SDL_Surface			*staff_sprites[3];
	SDL_Surface			*spark_sprite;
	SDL_Surface			*book_to_pick;
	SDL_Surface			*staff_to_pick;
	SDL_Surface			*spark_to_pick;
}						t_map;

void					free_map(t_map *map);
void					read_map_from_file(int fd, t_textures *textures,
							t_map **map);
void					write_map_to_file(int fd, t_map *map);
void					write_hud_to_file(int fd, t_hud hud);
void					read_hud_from_file(int fd, t_textures *textures,
							t_hud *hud);
void					write_spawn_to_file(int fd, t_coords spawn, int index);
void					read_spawn_from_file(int fd, t_coords *spawn,
							int *index);

#endif
