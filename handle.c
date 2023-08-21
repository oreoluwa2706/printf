#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function with limited conversion specifiers.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	char c;

	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			char specifier = *format++;
			switch (specifier)
			{
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					printf("%d", num);
					count++;
				}
				break;
				default:
					putchar('%');
					putchar(specifier);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(c);
			count++;
		}
	}

	va_end(args);
	return count;
}


