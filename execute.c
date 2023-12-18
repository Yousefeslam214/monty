#include "monty.h"

void execute(Data *data)
{
	int i = 0;
	char *str, *op ;

	instruction_t ops[] = {
		{"push", push},{"pall", pall},
		{"pall;", pall},{"pint", pint},
		{"pint;", pint},{"pop",pop},
		{"swap", swap},{"add", add},
		{"nop",nop},{"sub" ,sub},
		{"div", _div},
		{"swap", swap}, {"add", add},
		{"mul", mul},
		{"mod", mod}, {"rotl", rotl},
		{"rotr", rotr}, {"pop", pop},
		{NULL, NULL}
	};
	/*
	printf("data->line is : %s\n", data->line);
	printf("op is : %s\n", op);
	printf("data->line is len : %ld\n", strlen(data->line));
	*/
	
	/*
	if (strlen(data->line) > 10)
	{
		
			
			op = strtok(data->line, " \n\t");
			str = strtok(NULL, " ;\n\t");
			
		while ((op = strtok(data->line, " \n\t"))!=NULL)
		{
			str = strtok(NULL, " ;\n\t");
		}
	}
	else
	{*/
	op = strtok(data->line, " \n\t");
	str = strtok(NULL, " \n\t");
	/*}*/
	if (str)
		str = clear_number_from_semicolon(str);
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
	free_stack(data->stack);
	free(data->line);
	fclose(data->file);
	exit(EXIT_FAILURE);
}


