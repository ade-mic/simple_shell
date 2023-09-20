#include "main.h"
/**
 * _strcpy - function that copies a buffer from a string variable
 *	     to another
 *
 * @dest: pointer to the destination of the buffer to be copied
 * @src: pointer to the buffer to be copied
 *
 * Return: return @dest
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strlen - calculates the length of a string
 *
 * @s: the string whose length will be calculated
 *
 * Return: return the length of @s
*/

size_t _strlen(const char *s)
{
	int length;

	for (length = 0; s[length] != '\0'; length++)
		;

	return (length);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: the first string
 * @s2: the second string
 *
 * Return: return an integer less than, equal to,
 *	   or greater than zero
*/

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strcat - concatenate two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: a pointer to the concatenated string
 */
char *_strcat(char *str1, char *str2)
{
	size_t len1 = _strlen(str1);
	size_t len2 = _strlen(str2);
	char *result;

	result = malloc((len1 + len2) * sizeof(char));
	if (!result)
		return (NULL);
	_strcpy(result, str1);
	_strcpy(result + len1, str2);

	return (result);
}

/**
 * _strncmp - compares two string character by character untill n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of byte to compared
 * Return: 0 on success
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char)s2[i]);
		}

		if (s1[i] == '\0' || s2[i] == '\0')
		{
			break;
		}
	}
	return (0);
}
