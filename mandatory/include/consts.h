/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:08 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 06:34:53 by zech-chi         ###   ########.fr       */
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

# define WIN_NAME "ziko^2"
# define PATH_WEAPONS_INIT_STATE "mandatory/images/weapon/init_state/0.png"
# define PATH_WEAPONS_NORM_SHOOT_1 "mandatory/images/weapon/normal_shoot/img"
# define PATH_WEAPONS_ZOME_SHOOT_1 "mandatory/images/weapon/zome_shoot/img"
# define PATH_WEAPONS_RELOAD "mandatory/images/weapon/reload/img"
# define PATH_TARGET "mandatory/images/target/target.png"
# define PATH_DOOR "mandatory/images/door/door.png"
# define PATH_BLACK "mandatory/images/black/black.png"
# define PATH_WEAPON_MAGAZINE "mandatory/images/weapon_magazine/"
# define PATH_WEAPON_MAGAZINE_0 "mandatory/images/weapon_magazine/0.png"
# define PATH_CIRCLE "mandatory/images/circle/circle.png"
# define PATH_GAME_START_0 "mandatory/images/game_start/1.png"
# define PATH_GAME_START_1 "mandatory/images/game_start/2.png"
# define PATH_GAME_START_2 "mandatory/images/game_start/3.png"
# define PATH_GAME_START_3 "mandatory/images/game_start/4.png"
# define PATH_SKY "mandatory/images/sky/sky3.png"
# define PATH_SHOOT_TARGET "mandatory/images/shoot_target/shoot_target.png"
# define PNG ".png"

# define WEAPON_MAGAZIN_X 20
# define WEAPON_MAGAZIN_Y 600
# define WEAPON_MAGAZINE 10
# define WEAPON_WEDTH 640
# define WEAPON_HEIGHT 359
# define FRAMES_SHOOT1 11
# define FRAMES_ZOME1 20
# define FRAMES_RELOAD 83
# define WEAPONS 637

/*player consts*/
# define SPEED_JUMP (M_PI / 4.0)
# define POS_MINIMAP 25
# define RADIUS 2
# define SENS_LENGTH 15
# define N_STEPS 7
# define SCALE 150
# define WALK_SPEED 100
# define TURN_SPEED 4.5 * (M_PI / 180)


# define RELOAD_SOUND_PATH "music/reload_sound.mp3"
#endif
