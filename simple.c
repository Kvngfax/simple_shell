#include "shell.h"

/**
 * main - Main function for the simple shell
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: 0 on success, or error code on failure.
 */
int main(int argc, char **argv)
{
    int exe_ret = 0;

    if (argc > 1)
    {
        exe_ret = proc_file_commands(argv[1]);
    }
    else
    {
        fprintf(stderr, "Usage: simple_shell [filename]\n");
        return EXIT_FAILURE;
    }

    return exe_ret;
}

/**
 * proc_file_commands - Processes commands from a given file
 * @file_path: Path to the file containing the commands
 *
 * Return: 0 on success, or error code on failure.
 */
int proc_file_commands(char *file_path)
{
    FILE *fp = fopen(file_path, "r");
    if (!fp)
    {
        perror("simple_shell");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args;

    while ((read = _getline(&line, &len, fp)) != -1)
    {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0'; // Remove the newline

        // Tokenize the command and its arguments
        args = _strtok(line, " ");

        // Execute the command
        execute(args, args);

        // Free the allocated memory for the line
        free(line);
        line = NULL;
    }

    free(line); // Free any remaining allocations
    fclose(fp); // Close the file

    return EXIT_SUCCESS;
}
