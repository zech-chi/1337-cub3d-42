/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:08 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/09 15:07:32 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONSTS_H
# define CONSTS_H

# include <math.h>

# define BUFFER_SIZE 1

# define SUCCESS 0
# define FAILED 1

# define WHITE "\e[1;37m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define RESET "\e[m"\

# define PI M_PI
# define PI2 M_PI_2
# define _3PI2 (1.5 * M_PI)
# define _2PI (2.0 * M_PI)
# define _5PI (5 * M_PI)

# define WINDOW_HEIGHT 675
# define WINDOW_WIDTH 1200
# define MINIMAP_HEIGHT 201
# define MINIMAP_WIDTH 201
# define MINIMAP_RADIUS 100.5

# define NUMBER_RAYS 1200
# define PIXEL 1024
# define PIXEL_MINI 15
# define LEFT_RIGHT_STEP 2

# define ZONE 7
# define HORIZON 300
# define LOOK_SPEED 15

# define WEAPON_MAGAZIN_X 20
# define WEAPON_MAGAZIN_Y 600
# define WEAPON_MAGAZINE 10
# define PATH_WEAPON_MAGAZINE "weapon_magazine/"
# define WEAPON_WEDTH 640
# define WEAPON_HEIGHT 359
# define PATH_WEAPONS_INIT_STATE "weapon/init_state/img0.png"
# define PATH_WEAPONS_NORM_SHOOT_1 "weapon/normal_shoot1/img"
# define FRAMES_SHOOT1 11
# define PATH_WEAPONS_NORM_SHOOT_2 "weapon/normal_shoot2/img"
# define FRAMES_SHOOT2 42
# define PATH_WEAPONS_ZOME_SHOOT_1 "weapon/zome_shoot1/img"
# define FRAMES_ZOME1 20
# define PATH_WEAPONS_ZOME_SHOOT_2 "weapon/zome_shoot2/img"
# define FRAMES_ZOME2 44
# define PATH_WEAPONS_RELOAD "weapon/reload/img"
# define FRAMES_RELOAD 83
# define PNG ".png"
# define WEAPONS 637

/*player consts*/
# define SPEED_JUMP (M_PI / 4.0)
# define POS_MINIMAP 25
# define RADIUS 2
# define SENS_LENGTH 15
# define N_STEPS 7
# define SCALE 150
# define WALK_SPEED 100
# define TURN_SPEED 2.5 * (M_PI / 180)


# define RELOAD_SOUND_PATH "music/reload_sound.mp3"
#endif
