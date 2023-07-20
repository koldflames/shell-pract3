#include "main.h"

/**
 * aux_help - Help information for the builtin help.
 * Return: no return
 */
void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_alias - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_cd - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * get_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
 */
int get_help(data_shell *datash)
{

    if (datash->args[1] == 0)
        aux_help_general();
    else if (_strcmp(datash->args[1], "setenv") == 0)
        aux_help_setenv();
    else if (_strcmp(datash->args[1], "env") == 0)
        aux_help_env();
    else if (_strcmp(datash->args[1], "unsetenv") == 0)
        aux_help_unsetenv();
    else if (_strcmp(datash->args[1], "help") == 0)
        aux_help();
    else if (_strcmp(datash->args[1], "exit") == 0)
        aux_help_exit();
    else if (_strcmp(datash->args[1], "cd") == 0)
        aux_help_cd();
    else if (_strcmp(datash->args[1], "alias") == 0)
        aux_help_alias();
    else
        write(STDERR_FILENO, datash->args[0],
              _strlen(datash->args[0]));

    datash->status = 0;
    return (1);
}