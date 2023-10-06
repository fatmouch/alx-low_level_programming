#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file_name);
void close_file(int cf);

/**
 * create_buffer - This allocates 1024 bytes for a buffer
 * @file_name: File buffer name for storage of chars
 *
 * Return: Pointer to a new allocated buffer
 */
char *create_buffer(char *file_name)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file_name);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - This closes the file descriptors.
 * @cf: The file descriptor to close.
 */
void close_file(int cf)
{
	int cls;

	cls = close(cf);

	if (cls == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", cf);
		exit(100);
	}
}

/**
 * main - This copies contents of one file to another file
 * @argc: Number of arguments given to the program
 * @argv: This is an array of pointers to the arguments.
 *
 * Return: if successful reutrn 0
 *
 * Description: for the file parameters
 * If an argument count is incorrect - exit code 97 and print.
 * If file_from cannot be read or doesn't exist - exit code 98 and print.
 * If file_to cannot be written to or created - exit code 99 and print.
 * If file_to or file_from cannot be closed up - exit code 100 and print.
 */
int main(int argc, char *argv[])
{
	int from, to, rd, wt;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	rd = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		wt = write(to, buff, rd);
		if (to == -1 || wt == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		rd = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}
