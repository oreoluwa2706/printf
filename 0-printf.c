#include "main.h"

/**
 * _printf - check for this function
 * @format: check for this parameter
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list printf_char;
	int count_char;
	int s_len;

	count_char = 0;
	if (format == NULL)
	{
		return (-1);
	}
	va_start(printf_char, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count_char++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
		}
		if (*format == '%')
		{
			write(1, format, 1);
			count_char++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(printf_char, int);

			write(1, &c, 1);
			count_char++;
		}
		else if (*format == 's')
		{
			char *s_count = va_arg(printf_char, char*);

			s_len = 0;
			if (s_count[s_len] != '\0')
				s_len++;
			write(1, s_count, s_len);
			count_char += s_len;
		}
	}
	format++;
	va_end(printf_char);
	return (count_char);
}
