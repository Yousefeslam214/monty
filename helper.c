#include "monty.h"

int is_digit(char *str, unsigned int line_number)
{
	int i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			{
				fprintf(stderr, "L%u: usage: push integer\n",line_number);
				/*free_stack(global_data.stack);*/
				fclose(global_data.file);
				free(global_data.line);
				exit(EXIT_FAILURE);
			}
	i++;
	}
	return 1;
}
