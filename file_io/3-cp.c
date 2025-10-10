#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * print_error - print error and exit with code
 * @code: exit code
 * @fmt: printf-like format
 * @arg: filename or fd string
 */
void print_error(int code, const char *fmt, const char *arg)
{
	dprintf(STDERR_FILENO, fmt, arg);
	exit(code);
}

/**
 * open_from - open source file for reading (or exit 98)
 * @path: file path
 * Return: fd
 */
int open_from(const char *path)
{
	int fd = open(path, O_RDONLY);

	if (fd == -1)
		print_error(98, "Error: Can't read from file %s\n", path);
	return (fd);
}

/**
 * open_to - open destination file for writing (or exit 99)
 * @path: file path
 * Return: fd
 */
int open_to(const char *path)
{
	int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
		print_error(99, "Error: Can't write to %s\n", path);
	return (fd);
}

/**
 * safe_write - write exactly n bytes (handles partial writes)
 * @fd: destination fd
 * @buf: buffer
 * @n: bytes to write
 * @dst_name: destination filename (for error message)
 */
void safe_write(int fd, const char *buf, ssize_t n, const char *dst_name)
{
	ssize_t written = 0, w;

	while (written < n)
	{
		w = write(fd, buf + written, n - written);
		if (w == -1)
			print_error(99, "Error: Can't write to %s\n", dst_name);
		written += w;
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r;
	char buf[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_from(argv[1]);
	fd_to = open_to(argv[2]);

	while (1)
	{
		r = read(fd_from, buf, BUF_SIZE);
		if (r == -1)
			print_error(98, "Error: Can't read from file %s\n", argv[1]);
		if (r == 0)
			break;
		safe_write(fd_to, buf, r, argv[2]);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}
