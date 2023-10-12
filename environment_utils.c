#include "shell.h"

char **copy_environment(void);
void clean_env(void);
char **retrieve_env(const char *var);

/**
 * copy_environment - Duplicates the current environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */
char **copy_environment(void)
{
	char **new_environ;
	size_t size;
	int i;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		new_environ[i] = malloc(_strlen(environ[i]) + 1);

		if (!new_environ[i])
		{
			for (i
				free(new_environ[i]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[i], environ[i]);
	}
	new_environ[i] = NULL;

	return (new_environ);
}

/**
 * clean_env - Releases the memory occupied by the duplicated environment.
 */
void clean_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		free(environ[i]);
	free(environ);
}

/**
 * retrieve_env - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **retrieve_env(const char *var)
{
	int i, variable_length;;

	variable_length; = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], variable_length;) == 0)
			return (&environ[i]);
	}

	return (NULL);
}
