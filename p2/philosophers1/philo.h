/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:54:35 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/26 20:10:51 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* libraries */
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/* actions	*/
# define EAT			("\033[1;32mis eating")
# define SLEEP			("\033[1;33mis sleeping")
# define THINK			("\033[1;36mis thinking")
# define TAKE_L_FORK	("\033[1;35mhas taken a fork")
# define TAKE_R_FORK	("\033[1;35mhas taken a fork")
# define FINISH_MEAL	("\033[0;36mphilosophers finished eating")
# define DIE			("\033[1;91mdied")

/* arguments errors */
# define ARGS_NUM		("\033[1;91mWrong number of arguments, try 5\
 or 6\033[0m")
# define PHILO_NUM		("\033[1;91mThere has to be at least 1\
 philosopher\033[0m")
# define ONLY_DIGIT		("\033[1;91mArguments have to be represented as\
 digits\033[0m")
# define SIZE_MATTERS	("\033[1;91mArguments have to be greater than\
 0\033[0m")
# define DEATH_TIME		("\033[1;91mThe time_to_die has to be greater than\
 0\033[0m")
# define FOOD_TIME		("\033[1;91mThe time_to_eat has to be greater than\
 0\033[0m")
# define SLEEP_TIME		("\033[1;91mThe time_to_sleep has to be greater than\
 0\033[0m")

/* structures */
typedef struct s_philo
{
	int				philo_id;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				eat_x_times;
	int				ate_x_times;
	int				*already_ate_max;
	long int		last_meal_time;
	long int		*start_time;
	int				stop;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*main_lock;
	pthread_mutex_t	*priv_lock;
	pthread_mutex_t	*write_message;
}				t_philo;

typedef struct s_table
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_x_times;
	int				already_ate_max;
	pthread_t		*threads;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_message;
	long int		start_time;
	pthread_mutex_t	main_lock;
	pthread_mutex_t	*priv_lock;
}				t_table;

/* arguments check */
int				set_check_args(t_table *table, int argc, char **argv);
void			set_arguments(t_table *table, int argc, char **argv);

/* control */
int				meal_control(t_table *table, t_philo *philo);
void			control(t_table *table, t_philo *philo);

/* destroy mutexes and free */
void			destroy(t_table *table);
void			free_all(t_table *table);

/* display message */
int				error_message(char *message, int print_usage);
int				error_message_args(t_table *table);
void			print_info(t_philo *philo, char *action);

/* initialize */
int				init_all(t_table *table);
void			init_philo(t_table *table, t_philo *philo);
int				init_mutex(t_table *table);
int				init_threads(t_table *table);

/* routine */
void			*philo_routine(void *arg);
void			update_meal_status(t_philo *philo);
int				meal(t_philo	*philo);
int				alive_check(t_philo *philo);

/* time */
long int		get_time_now(void);
void			new_sleep(int mil_sec);
int				join_threads(t_table *table);

/* utils */
void			put_char(char c, int fd);
void			put_string(char *s, int fd);
int				digit_check(char *c);
int				is_int(char *str);
int				atoi_philo(char *str);
#endif