/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:51:03 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/12 10:00:11 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTS_BONUS_H
# define CONSTS_BONUS_H

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
# define _3PI2 4.71238898038  // 1.5 * M_PI
# define _2PI 6.28318530718   // 2.0 * M_PI
# define _5PI 15.7079632679   // 5 * M_PI

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
# define PATH_WEAPONS_INIT_STATE "bonus/images/weapon/init_state/0.png"
# define PATH_WEAPONS_NORM_SHOOT_1 "bonus/images/weapon/normal_shoot/img"
# define PATH_WEAPONS_ZOME_SHOOT_1 "bonus/images/weapon/zome_shoot/img"
# define PATH_WEAPONS_RELOAD "bonus/images/weapon/reload/img"
# define PATH_TARGET "bonus/images/target/target.png"
# define PATH_DOOR "bonus/images/door/door.png"
# define PATH_BLACK "bonus/images/black/black.png"
# define PATH_WEAPON_MAGAZINE "bonus/images/weapon_magazine/"
# define PATH_WEAPON_MAGAZINE_0 "bonus/images/weapon_magazine/0.png"
# define PATH_CIRCLE "bonus/images/circle/circle.png"
# define PATH_GAME_START_0 "bonus/images/game_start/1.png"
# define PATH_GAME_START_1 "bonus/images/game_start/2.png"
# define PATH_GAME_START_2 "bonus/images/game_start/3.png"
# define PATH_GAME_START_3 "bonus/images/game_start/4.png"
# define PATH_SKY "bonus/images/sky/sky.png"
# define PATH_SHOOT_TARGET "bonus/images/shoot_target/shoot_target.png"
# define PNG ".png"

# define WEAPON_MAGAZIN_X 20
# define WEAPON_MAGAZIN_Y 600
# define WEAPON_MAGAZINE 10
# define WEAPON_WEDTH 640
# define WEAPON_HEIGHT 359
# define FRAMES_SHOOT1 18
# define FRAMES_ZOME1 20
# define FRAMES_RELOAD 83
# define WEAPONS 637

/*player consts*/
# define SPEED_JUMP 0.78539816339  // M_PI / 4.0
# define POS_MINIMAP 25
# define RADIUS 2
# define SENS_LENGTH 15
# define N_STEPS 7
# define SCALE 150
# define WALK_SPEED 100
# define TURN_SPEED 0.07853981634  // 4.5 * (M_PI / 180)

# define RELOAD_SOUND_PATH "bonus/music/reload_sound.mp3"
# define WAR_SOUND_PATH "bonus/music/war.mp3"
# define SHOOT_SOUND_PATH "bonus/music/shoot_sound.mp3"
#endif
