/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:26:11 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/15 19:47:46 by caaubert         ###   ########.fr       */
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

typedef struct s_rules
{
	int			number_of_coders;
	int			time_to_burnout;
	int			time_to_compile;
	int			time_to_debug;
	int			time_to_refactor;
	int			compiles_required;
	int			dongle_cooldown;
	char		*scheduler;
	
}				t_rules;


typedef struct s_coder
{
	int			id;
	int			time_to_burnout;
	int			time_to_compile;
	int			time_to_debug;
	int			time_to_refactor;
	int			actual_compiles;
	int			last_compile;
	bool		alive;
	pthread_t	coder;
}				t_coder;

typedef struct s_monitoring
{
	int				number_of_coders;
	int				compiles_required;
	int				dongle_cooldown;
	char			*scheduler;
	pthread_cond_t	death;
	pthread_t 		manager;
}			t_monitoring;

bool	args_checking(int argc, char *argv[]);
t_rules get_rules(char *argv[]);
void	run_startup(t_rules rules);

#endif