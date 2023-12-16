#include "monty.h"
int is_digit(char *str, unsigned int line_number)
{
	int i;
	if (str[0] == '-')
		str++;
	for (i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			{
				fprintf(stderr, "L%u: usage: push integer\n",line_number);
		/*free_stack(global_data.stack);*/
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
			}
			
	}
	return 1;
}



void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int num;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		/*free_stack(global_data.stack);*/
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	printf("%s\n",global_data.str);
	is_digit(global_data.str, line_number);
	
	num = atoi(global_data.str);
	new_node->n = num;
	new_node->prev = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (!stack || !*stack)
		return;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
	(void)line_number;
}
