#include "monty.h"

void execute(Data *data)
{
	int i = 0;
	char *str, *op;

	instruction_t ops[] = {
		{"push", push},{"pall", pall},{"pall;", pall},{NULL, NULL}
	};
	op = strtok(data->line, " \n\t");
	str = strtok(NULL, " \n\t");
	if (op == NULL)
		return;
	else if (op[0] == '#')
		return;
	if(data->line_number == 0)
	{
		if( strcmp("pall", ops[i].opcode) == 0)
		{
			
		}
	}
	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			
				data->str = str ? str : "";
				ops[i].f(data->stack, data->line_number);
				return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", data->line_number, op);
	/*free_stack(data->stack);*/
	free(data->line);
	fclose(data->file);
	exit(EXIT_FAILURE);
}


