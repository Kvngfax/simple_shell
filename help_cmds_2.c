#include "shell.h"

void display_help_env(void);
void display_help_setenv(void);
void display_help_unsetenv(void);
void display_help_history(void);

/**
 * display_help_env - Provides information on the 'env' builtin command.
 * Usage: env
 * Description: Prints the current environment variables.
 */
void display_help_env(void)
{
	char *msg = "env: env\n\tPrints the current env.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * display_help_setenv - Provides information on the 'setenv' builtin command.
 * 				Usage: setenv [VARIABLE] [VALUE]
 */
void display_help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * display_help_unsetenv - Provides information on the 'unsetenv' builtin command.
 * 					Usage: unsetenv [VARIABLE]
 */
void display_help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
