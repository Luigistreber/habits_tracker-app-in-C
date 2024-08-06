/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:42:08 by luigi_streb       #+#    #+#             */
/*   Updated: 2024/08/06 17:15:59 by luigi_streb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "habit_tracker.h"

int	main(void)
{
	const char	*filename = "habits.dat";
	int			choice;
	char		buffer[256];
	int			result;

	while (1)
	{
		printf("Aplicación de Seguimiento de Hábitos\n");
		printf("1. Añadir hábito\n");
		printf("2. Marcar hábito como completado\n");
		printf("3. Ver hábitos\n");
		printf("4. Salir\n");
		printf("Ingrese su opción: ");
		if (fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			result = sscanf(buffer, "%d", &choice);
			if (result != 1)
			{
				printf("Entrada inválida. Intente de nuevo.\n");
				continue ;
			}
		}
		else
		{
			printf("Error al leer la opción.\n");
			continue ;
		}
		switch (choice)
		{
			case 1:
				add_habit(filename);
				break ;
			case 2:
				mark_habit_completed(filename);
				break ;
			case 3:
				view_habits(filename);
				break;
			case 4:
				return 0;
			default:
				printf("Opción inválida. Intente de nuevo.\n");
		}
		printf("\n");
	}
	return (0);
}
