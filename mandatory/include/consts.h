/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:08 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 18:09:20 by zech-chi         ###   ########.fr       */
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
# define _3PI2 4.71238898038  // 1.5 * M_PI
# define _2PI 6.28318530718   // 2.0 * M_PI
# define _5PI 15.7079632679   // 5 * M_PI

# define WINDOW_HEIGHT 675
# define WINDOW_WIDTH 1200
# define NUMBER_RAYS 1200
# define PIXEL 1024
# define WIN_NAME "ziko^2"
# define N_STEPS 7
# define SCALE 150
# define WALK_SPEED 100
# define TURN_SPEED 0.06108652381  // 3.5 * (M_PI / 180)

#endif
