/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

// int check_pipe(char *instruction)
// {
//   int	i;

//   i = 0;
//   while (instruction[i])
//     {
//       if (instruction[i] == '|')
// 	return (SUCCESS);
//       i += 1;
//     }
//   return (ERROR);
// }

// int		first_pipe_exec(char *instruction, t_env *env)
// {
//   pid_t		pid;

//   if ((pid = fork()) == -1)
//     return (format(2, "Failed to fork\n"));
//   if (pid == 0)
//     {
//       dup2(env->fd[1], 1);
//       close(env->fd[0]);
//       launch_command(instruction, env);
//       exit(1);
//     }
//   else
//     {
//       close(env->fd[1]);
//       env->save = env->fd[0];
//     }
//   return (SUCCESS);
// }

// int		multi_pipe_exec(char *instruction, t_env *env)
// {
//   pid_t		pid;

//   if ((pid = fork()) == -1)
//     return (format(2, "Failed to fork\n"));
//   if (pid == 0)
//     {
//       dup2(env->save, 0);
//       dup2(env->fd[1], 1);
//       close(env->fd[0]);
//       launch_command(instruction, env);
//       exit(1);
//     }
//   else
//     {
//       close(env->fd[1]);
//       close(env->save);
//       env->save = env->fd[0];
//     }
//   return (SUCCESS);
// }

// int		end_pipe_exec(char *instruction, t_env *env)
// {
//   pid_t		pid;

//   if ((pid = fork()) == -1)
//     return (format(2, "Failed to fork\n"));
//   if (pid == 0)
//     {
//       if (env->redir_pipe == true)
// 	env->redir = true;
//       dup2(env->fd[0], 0);
//       close(env->save);
//       close(env->fd[1]);
//       launch_command(instruction, env);
//       exit(1);
//     }
//   else
//     {
//       close(env->fd[0]);
//       close(env->fd[1]);
//       close(env->save);
//     }
//   return (SUCCESS);
// }

// int		exec_pipe(char *instruction, int pipe_index,
// 			  int max_index, t_env *env)
// {
//   (pipe_index < max_index) ? pipe(env->fd) : 0;
//   if (pipe_index == 0)
//     {
//       if (first_pipe_exec(instruction, env) == ERROR)
// 	return (ERROR);
//     }
//   else if (pipe_index == max_index)
//     {
//       if (end_pipe_exec(instruction, env) == ERROR)
// 	return (ERROR);
//     }
//   else
//     if (multi_pipe_exec(instruction, env) == ERROR)
//       return (ERROR);
//   return (SUCCESS);
// }

// void	wait_end_process(char **tab)
// {
//   int		i;
//   int		status;

//   i = 0;
//   while (tab[i])
//     {
//       wait(&status);
//       i += 1;
//     }
// }

// int	is_valid_pipe(char **tab)
// {
//   int		i;

//   i = 0;
//   if (tab_len(tab) == 1)
//     return (ERROR);
//   while (tab[i])
//     {
//       if (is_empty(tab[i]) == ERROR)
// 	return (ERROR);
//       i += 1;
//     }
//   return (SUCCESS);
// }

// int		pipe_command(char *instruction, t_env *env)
// {
//   char		**tab;
//   int		i;

//   i = 0;
//   tab = separator_to_tab(instruction , '|');
//   if (is_valid_pipe(tab) == ERROR)
//     {
//       (tab != NULL) ? free_tab(tab) : 0;
//       return (format(2, "Invalid null command.\n"));
//     }
//   while (tab[i])
//     {
//       if (exec_pipe(tab[i], i, tab_len(tab) - 1, env) == ERROR)
// 	return (format(2, "Pipe failed\n"));
//       i += 1;
//     }
//   wait_end_process(tab);
//   (tab != NULL) ? free_tab(tab) : 0;
//   return (SUCCESS);
// }
