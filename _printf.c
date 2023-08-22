#include "main.h"

void check_buffer(char buffer[], int *buff_ind);

/**
 * _printf - check for this function
 * @format: check for this parameter.
 * Return: int.
 */
int _printf(const char *format, ...)
{
	int a, output, output_char, buffer_index;
	int flags, precision, width, size;
	va_list list;
	char buffer[BUFF_SIZE];

	output = 0,
	output_char = 0;
	buffer_index = 0;
	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buffer_index++] = format[a];
			if (buffer_index == BUFF_SIZE)
				check_buffer(buffer, &buffer_index);
			output_char++;
		}
		else
		{
			check_buffer(buffer, &buffer_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			output = handle_print(format, &a, list, buffer,
				flags, width, precision, size);
			if (output == -1)
				return (-1);
			output_char += output;
		}
	}
	check_buffer(buffer, &buffer_index);
	va_end(list);
	return (output_char);
}

/**
 * check_buffer - check for this function to print buffer
 * @buffer: Array of chars
 * @buffer_index: Index at which to add next char, represents the length.
 */
void check_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);
	*buffer_index = 0;
}

