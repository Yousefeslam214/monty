#include "monty.h"



void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int num;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
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


void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if(!top)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(global_data.line);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
		printf("%d\n", top->n);
}

/**
 * pop - delete top
 * @stack: ...
 * @line_number: ...
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(global_data.file);
		free_stack(global_data.stack);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	*stack = (*stack)->next;
	free(cur);
}
