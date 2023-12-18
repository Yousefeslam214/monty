#include "monty.h"


void sub(stack_t **stack, unsigned int line_number)
{
    int sub = 0;
    stack_t *cur = *stack;
    
    if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
    sub = ((*stack)->next->n) - (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->n = sub;
    free(cur);
}
void _div(stack_t **stack, unsigned int line_number)
{
    int div_num = 0;
    stack_t *cur = *stack;
    if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
    if (cur->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
    div_num = (*stack)->next->n / (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->n = div_num;
    free(cur);
}
