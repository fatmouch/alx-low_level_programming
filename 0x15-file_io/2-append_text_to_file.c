#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - this function appends text at the end of a file.
 * @filename: this is a pointer to the name of the file to append text to.
 * @text_content: The is the string to be added to the end of the file.
 *
 * Return: If function fails or filename is NULL, return -1.
 *         If file doesn't exist then user lacks write permissions, retun -1.
 *         Otherwise return 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int op, wt, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	wt = write(op, text_content, length);

	if (op == -1 || wt == -1)
		return (-1);

	close(op);

	return (1);
}
