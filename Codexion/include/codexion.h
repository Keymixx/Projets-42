/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:26:11 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/20 17:08:08 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# define NB_CODERS "number_of_coders  "
# define BURNOUT "time_to_burnout  "
# define COMPILE "time_to_compile  "
# define DEBUG "time_to_debug  "
# define REFACTOR "time_to_refactor  "
# define NB_COMPILES "number_of_compiles_required  "
# define DONGLE "dongle_cooldown  "
# define SCHELUDER "dongle_cooldown"

# define LIST_ARGS

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_dongles
{
	pthread_mutex_t dongle_mutex;
	int				dongle_cooldown;
	int				queue[2];
	bool			init;
}				t_dongles;

typedef struct s_coder
{
	int				id;
	long long		time_to_burnout;
	int				time_to_compile;
	int				time_to_debug;
	int				time_to_refactor;
	int				actual_compiles;
	int				*all_alive;
	
	long long			last_compile;
	long long			*time;
	
	pthread_cond_t	*death_cond;
	pthread_mutex_t *death_mutex;
	t_dongles 		*l_dongle;
	t_dongles 		*r_dongle;
	pthread_mutex_t *message;
	pthread_t		thread;

}				t_coder;

typedef struct s_data
{
	int				number_of_coders;
	int				time_to_compile;
	int				time_to_debug;
	int				time_to_refactor;
	int				compiles_required;
	int				dongle_cooldown;
	char			*scheduler;
	int				all_alive;
	
	long long			time_to_burnout;
	long long			time;
	
	pthread_cond_t	death_cond;
	pthread_mutex_t death_mutex;
	pthread_mutex_t message;
	
	t_dongles		**dongles;
	t_coder			**coders;
}			t_data;


bool			args_checking(int argc, char *argv[]);
t_data 			get_data(char *argv[]);
void			run_startup(t_data *data);
void 			coders_init(t_data *data);
void			dongle_init(t_data *data);
int				ft_usleep(long long milliseconds, t_coder *coder);
void 			ft_message(char *str, t_coder *coder);
long long		get_current_time(void);
void 			*work(void *arg);
bool 			project_finish(t_data *data);

#endif