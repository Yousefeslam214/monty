#include "monty.h"

void execute(Data *data)
{
	int i = 0;
	char *str, *op;

	instruction_t ops[] = {
		{"push", push},{"push", push_end},{"pall", pall}
	};
	op = strtok(data->line, " \n\t");
	str = strtok(NULL, " \n\t");
	if (op == NULL)
		return;
	else if (op[0] == '#')
		return;
	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			
				data->str = str ? str : "e";
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
