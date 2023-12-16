#include "monty.h"


/**
 * swap - swap first 2 element of the stack
 * @stack: ...
 * @line_number: ...
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - add first 2 element of the stack
 * @stack: ...
 * @line_number: ...
 */
void add(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cur = *stack;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n += temp;
	free(cur);
}



/**
 * nop - do nothing
 * @stack: ...
 * @line_number: ...
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
