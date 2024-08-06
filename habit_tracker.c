/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habit_tracker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:44:22 by luigi_streb       #+#    #+#             */
/*   Updated: 2024/08/05 21:44:31 by luigi_streb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "habit_tracker.h"

void	add_habit(const char *filename)
{
	FILE	*file;
	t_habit	h;
	char	buffer[256];
	int		result;

	file = fopen(filename, "a");
	if (!file)
	{
		perror("Error al abrir el archivo");
		return ;
	}

	printf("Ingrese el nombre del hábito: ");
	if (fgets(h.name, sizeof(h.name), stdin) != NULL)
	{
		h.name[strcspn(h.name, "\n")] = '\0';
	}
	else
	{
		printf("Error al leer el nombre del hábito.\n");
		fclose(file);
		return ;
	}

	printf("Ingrese el número total de días para el objetivo: ");
	if (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		result = sscanf(buffer, "%d", &h.total_days);
		if (result != 1 || h.total_days <= 0)
		{
			printf("Número de días inválido. Intente de nuevo.\n");
			fclose(file);
			return ;
		}
	}
	else
	{
		printf("Error al leer el número total de días.\n");
		fclose(file);
		return ;
	}
	h.completed_days = 0;
	fwrite(&h, sizeof(t_habit), 1, file);
	fclose(file);
	printf("Hábito añadido exitosamente.\n");
}

void	mark_habit_completed(const char *filename)
{
	FILE	*file;
	FILE	*temp_file;
	t_habit	h;
	char	name[MAX_HABIT_NAME_LENGTH];
	int		found;

	found = 0;
	file = fopen(filename, "r+b");
	if (!file)
	{
		perror("Error al abrir el archivo");
		return ;
	}

	temp_file = fopen("temp.dat", "w+b");
	if (!temp_file)
	{
		perror("Error al abrir el archivo temporal");
		fclose(file);
		return ;
	}

	printf("Ingrese el nombre del hábito a marcar como completado: ");
	if (fgets(name, sizeof(name), stdin) != NULL)
	{
		name[strcspn(name, "\n")] = '\0';
	}
	else
	{
		printf("Error al leer el nombre del hábito.\n");
		fclose(file);
		fclose(temp_file);
		return ;
	}

	while (fread(&h, sizeof(t_habit), 1, file))
	{
		if (strcmp(h.name, name) == 0)
		{
			if (h.completed_days < h.total_days)
			{
				h.completed_days++;
				printf("Hábito marcado como completado.\n");
				found = 1;
			}
			else
			{
				printf("El hábito ya está completo.\n");
			}
		}
		fwrite(&h, sizeof(t_habit), 1, temp_file);
	}
	fclose(file);
	fclose(temp_file);
	remove(filename);
	rename("temp.dat", filename);
	if (!found)
	{
		printf("Hábito no encontrado.\n");
	}
}

void	view_habits(const char *filename)
{
	FILE	*file;
	t_habit	h;

	file = fopen(filename, "rb");
	if (!file)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	printf("Lista de hábitos:\n");
	while (fread(&h, sizeof(t_habit), 1, file))
	{
		printf("Nombre: %s\n", h.name);
		printf("Completados: %d/%d días\n", h.completed_days, h.total_days);
		printf("------------------------\n");
	}
	fclose(file);
}