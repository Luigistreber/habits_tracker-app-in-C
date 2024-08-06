/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habit_tracker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:23:25 by luigi_streb       #+#    #+#             */
/*   Updated: 2024/08/05 19:51:06 by luigi_streb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HABIT_TRACKER_H
# define HABIT_TRACKER_H
# define MAX_HABIT_NAME_LENGTH 100
# define MAX_FILE_NAME_LENGTH 100
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>


typedef struct s_habit
{
	char	name[MAX_HABIT_NAME_LENGTH];
	int		completed_days;
	int		total_days;
}	t_habit;

void	add_habit(const char *filename);
void	mark_habit_completed(const char *filename);
void	view_habits(const char *filename);

#endif
