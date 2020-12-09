/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:55:12 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 14:55:27 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_sound		*initsound(void)
{
	t_sound	*sound;

	sound = ft_memalloc(sizeof(t_sound));
	sound->on = 1;
	sound->possible = 1;
	sound->result = FMOD_System_Create(&sound->fmodsystem);
	if (sound->result != FMOD_OK)
		sound->possible = 0;
	else
		sound->result = FMOD_System_Init(sound->fmodsystem, 2,\
		FMOD_INIT_NORMAL, 0);
	if (sound->result != FMOD_OK)
		sound->possible = 0;
	else
	{
		FMOD_Channel_SetVolume(sound->channel, 1.0f);
		sound->result = FMOD_System_CreateChannelGroup(sound->fmodsystem,\
		"MUSIC", &sound->music);
	}
	return (sound);
}

void		loadsound(t_sound *sound, const char *filename)
{
	sound->currentsound = (char*)filename;
	sound->result = FMOD_Sound_Release(sound->sound);
	sound->result = FMOD_System_CreateStream(sound->fmodsystem,\
	sound->currentsound, FMOD_DEFAULT, 0, &sound->sound);
}

void		playsound(t_sound *sound, int pause)
{
	sound->result = FMOD_System_PlaySound(sound->fmodsystem,\
	sound->sound, sound->music, pause, &sound->channel);
	FMOD_Channel_SetMode(sound->channel, FMOD_LOOP_NORMAL);
}

t_color		ft_shading(t_color color, double h)
{
	color.r *= 1 - h;
	color.g *= 1 - h;
	color.b *= 1 - h;
	return (color);
}
