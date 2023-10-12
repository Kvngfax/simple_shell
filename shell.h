#ifndef _MUSH_H_
#define _MUSH_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define END_OF_FILE -2
#define EXIT -3

/* Global environemnt */
extern char **environ;
/* Global program name */
char *name;
/* Global history counter */
int hist;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @func: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*func)(char **argv, char **beginning);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases linked list */
alias_t *aliases;

/* Main Helpers */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_dir(char *path);
int execute(char **args, char **beginning);
void free_list(list_t *head);
char *_itoa(int num);

/* Input Helpers */
void resolve_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_aliases(char **args);

/* String functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
size_t _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Built Ins */
int (*get_builtin(char *command))(char **args, char **beginning);
int process_exit(char **args, char **beginning);
int process_env(char **args, char __attribute__((__unused__)) **beginning);
int process_setenv(char **args, char __attribute__((__unused__)) **beginning);
int process_unsetenv(char **args,
		char __attribute__((__unused__)) **beginning);
int process_cd(char **args, char __attribute__((__unused__)) **beginning);
int process_alias(char **args, char __attribute__((__unused__)) **beginning);
int process_help(char **args, char __attribute__((__unused__)) **beginning);

/* Built In Helpers */
char **copy_environment(void);
void clean_env(void);
char **retrieve_env(const char *var);

/* Error Handlers */
int create_error(char **args, int err);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/* Linked List Helpers */
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

void display_all_help(void);
void display_alias_help(void);
void display_cd_help(void);
void display_exit_help(void);
void display_help_cmd(void);
void display_help_env(void);
void display_help_setenv(void);
void display_help_unsetenv(void);
void display_help_history(void);

int process_cmds(char *fpath, int *exe_ret);
#endif /* _MUSH_H_ */
