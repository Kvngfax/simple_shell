#include "shell.h"

/**
 * _strlen - Gets the length of string
 * @s: String whose length is to be found
 * Return: Length of string s
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len]; len++)
		;

	return (len);
}

/**
 * _strcat - Concatenates two strings
 * @dest: First string
 * @src: Second string
 * Return: Pointer to concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	int i, dest_len;

	if (src == NULL)
		return (dest);
	dest_len = _strlen(dest);

	for (i = 0; src[i]; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);

}

/**
 * _strncat - Concatenate first n bytes of string src with
 * string dest
 * @dest: First string
 * @src: Second string
 * @n: Number of bytes of src to concatenate with dest
 * Return: Pointer to concatenated string
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	int dest_len;
	size_t i;

	dest_len = _strlen(dest);
	for (i = 0; i < n && src[i]; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strcpy - Copies a string
 * @dest: Address of new string
 * @src: String to be copied
 * Return: Pointer to copied string
 */
char *_strcpy(char *dest, const char *src)
{
	int  i;

	if (!src)
		return (NULL);
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strchr - Checks for a character is in a string
 * @s: String to check
 * @c: Character to find
 * Return: Pointer to position of character in a string
 */
char *_strchr(char *s, char c)
{
	int i, len;

	len = _strlen(s);
	i = 0;
	while (s[i] != c)
	{
		if (i == len)
			return (NULL);
		i++;
	}
	return (s + i);
}
