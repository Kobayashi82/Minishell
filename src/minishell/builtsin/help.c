/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:58:57 by vzurera-          #+#    #+#             */
/*   Updated: 2024/05/06 20:22:14 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	help(t_data *d)
{
	print(d, 1, Y"\n\tMINI"BR"SHELL"G" 1.0 "C"(Builtins)\n\n", R);
	print(d, 1, BR" cd:\t\t"Y"Change the working directory\n", J);
	print(d, 1, BR" pwd:\t\t"Y"Print the working directory\n", J);
	print(d, 1, BR" echo:\t\t"Y"Print a message\n", J);
	print(d, 1, BR" env:\t\t"Y"List the environment and shell variables\n", J);
	print(d, 1, BR" export:\t"Y"Set environment variables\n", J);
	print(d, 1, BR" unset:\t\t"Y"Delete variables\n", J);
	print(d, 1, BR" exit:\t\t"Y"Close minishell\n", J);
	print(d, 1, BR" history:\t"Y"Show a list of previous commands\n", J);
	print(d, 1, BR" banner:\t"Y"Display the minishell banner\n", J);
	print(d, 1, BR" help:\t\t"Y"Show this help\n\n"NC, J);
	print(d, 1, C" All "G"builtins"C" comes with the flag "Y"--help", J);
    print(d, 1, C" and "Y"--version\n", J);
	print(d, 1, C"\n Also, you can create "G"shell variables ", J);
	print(d, 1, C "using the format"Y" VAR=VALUE\n\n", J);
    print(d, 1, G" Special variables: "Y"!!"C", "Y"$$"C", "Y"$?"C", "Y"$_", J);
    print(d, 1, C","Y"$RANDOM"C", "Y"$SECONDS"C"\n\n", J);
    print(d, 1, " Check the "G"documentation"C" for", J);
	print(d, 1, " a complete list of features\n\n", P);
	return (0);
}
