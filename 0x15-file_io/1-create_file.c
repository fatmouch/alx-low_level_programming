#include "main.h"
#include <stdio.h>

/**
 * create_file - this function is to create a file.
 * @filename: A pointer to the name of the file to be created.
 * @text_content: A pointer to a string to be written into the file.
 *
 * Return: If function is successful, returns 1.
 *         Otherwise, if failed, returns -1.
 */
int create_file(const char *filename, char *text_content)
{
	int ft, wt, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	ft = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wt = write(ft, text_content, length);

	if (ft == -1 || wt == -1)
		return (-1);

	close(ft);

	return (1);
}
