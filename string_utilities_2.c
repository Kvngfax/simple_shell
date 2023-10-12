#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if s1 == s2
 *         Positive byte difference if s1 > s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, s1_len, count;

	s1_len = _strlen(s1);
	count = 0;
	for (i = 0; i < s1_len; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
		{
			count = s1[i] - s2[i];
			break;
		}
	}
	return (count);
}

/**
 * _strncmp - Compare the first n bytes of two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes to be compared
 * Return: 0 if s1 == s2
 *         Positive byte differnce if s1 > s2
 *         Negative byte differnce if s1 < s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}

/**
 * _strspn - Gets the length of a prefix substring
 * @s: String to be searched
 * @accept: Prefix to search for
 * Return: The number of bytes in s which consists only of bytes from accept
 */
size_t _strspn(char *s, char *accept)
{
	size_t temp, count;
	int i, j, s_len, accept_len;

	s_len = _strlen(s);
	accept_len = _strlen(accept);
	count = 0;

	for (i = 0; i < s_len; i++)
	{
		temp = count;
		for (j = 0; j < accept_len; j++)
		{
			if (s[i] == accept[j])
				++count;
		}
		if (temp == count)
			break;
	}
	return (count);

}
