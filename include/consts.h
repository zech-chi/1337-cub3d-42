/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:08 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/03 17:47:58 by zech-chi         ###   ########.fr       */
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

# define WINDOW_HEIGHT 800
# define WINDOW_WIDTH 1200
# define MINIMAP_HEIGHT 401
# define MINIMAP_WIDTH 401

# define NUMBER_RAYS 1200
# define PIXEL 1024
# define PIXEL_MINI 32
# define LEFT_RIGHT_STEP 2

# define ZONE 7
# define HORIZON 300
# define LOOK_SPEED 50

# define WEAPONS 87
# define WEAPON_WEDTH 640
# define WEAPON_HEIGHT 359
# define PATH_WEAPONS "weapon/img"
# define PNG ".png"

/*player consts*/
# define RADIUS 4
# define SENS_LENGTH 15
# define N_STEPS 3
# define SCALE 150
# define WALK_SPEED 100
# define TURN_SPEED 2.5 * (M_PI / 180)

#endif
