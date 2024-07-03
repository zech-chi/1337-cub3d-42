/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:08 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/03 12:14:43 by zelabbas         ###   ########.fr       */
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

# define WINDOW_HEIGHT 800
# define WINDOW_WIDTH 1200
# define NUMBER_RAYS 1200
# define PIXEL 1024
# define PIXEL_MINI 32
# define N_STEPS 5

# define HORIZON 300
# define LOOK_SPEED 50

# define WEAPONS 87
# define WEAPON_WEDTH 640
# define WEAPON_HEIGHT 359
# define PATH_WEAPONS "weapon/img"
# define PNG ".png"

/*player consts*/
# define WALK_SPEED 80
# define TURN_SPEED 5 * (M_PI / 180)

#endif
