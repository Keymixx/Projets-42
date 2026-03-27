/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:26:11 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/27 18:38:21 by caaubert         ###   ########.fr       */
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
# define SCHELUDER "scheduler  "

# define LIST_ARGS

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data t_data;
typedef struct s_coder t_coder;

typedef struct s_dongles
{
	pthread_mutex_t dongle_mutex;
	pthread_cond_t 	dongle_cond;
	t_coder			*queue[2];
	int				dongle_cooldown;
	long long		dongle_avaible;
	char			*scheduler;
	bool			is_taken;
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

	long long			deadline;
	
	pthread_cond_t	*finish_cond;
	pthread_mutex_t *death_mutex;
	t_dongles 		*l_dongle;
	t_dongles 		*r_dongle;
	pthread_mutex_t *message;
	pthread_t		thread;

	t_data			*data;
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
	bool			finish;
	
	long long			time_to_burnout;
	long long			time;
	
	pthread_cond_t	finish_cond;
	pthread_mutex_t death_mutex;
	pthread_mutex_t message;

	pthread_t		manager;
	
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
int				project_finish(t_data *data);
void			lock_mutex(t_dongles *dongle, t_coder *coder);
void 			unlock_mutex(t_dongles *dongle, t_coder *coder);
void 			*manager(void *arg);

#endif