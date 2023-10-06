#include <stdlib.h>
#include "main.h"

/**
 * read-textfile- this reads text file to the POSIX standard output.
 * @filename: the text file to be read and printed.
 * @letters: the numbers of letters to be read and printed.
 * return: wt- actual number of the bytes that was read and printed.
 * 0 when the function fails or filename when is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;
	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 ||w !=r)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(0);

	return (w);
}
