/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:27:32 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/27 12:36:11 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		countCommands(char **splitLine)
{
	int	i;

	i = 0;
	while (splitLine[i] != NULL)
		i++;
	return (i);
}

void	fillStructs(int amount, char **splitLine, t_command *commands)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		printf("|%d|\n", i);
		commands[i].arg_list = splitLine[i];
		printf("|%s|\n", commands[i].arg_list);
		i++;
	}
	return ;
}

void	parse_line(char *line, t_command *commands)
{
	char	**splitLine;
	int		amount;

	splitLine = ft_split(line, ';');
	amount = countCommands(splitLine);
	commands = ft_calloc(amount, sizeof(t_command));
	fillStructs(amount, splitLine, commands);
	return ;
}
