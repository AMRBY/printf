#include "main.h"
/**
 * _printf - prints anything
 * @format: list of types per arguments passed
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, k = 0;
	char *arg;
	va_list p;
	void (*fun)(va_list, int);

	if (format == NULL)
		return (-1);

		va_start(p, format);
		while (format[i] != '\0')
		{
			if (format[i] != '%')
			{
				write(1, &format[i], 1);
				k++;
				i++;
			}
			else
			{
				arg = va_arg(p, char*);
				while (arg && arg[j])
				{
					write(1, &arg[j], j);
					j++;
					k++;
				}
				va_end(p);
				i = i + 2;
			}
		}

	return (k);
}
