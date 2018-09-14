#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("bfc: no input files\n");
		return (1);
	}

	char	c;
	FILE	*bf_code = fopen(argv[1], "r");
	FILE	*bf_out = fopen("bf.c", "w");

	fprintf(bf_out, "int main(){int i=0;char arr[30000];memset(arr,0,sizeof(arr));");
	c = getc(bf_code);
	while (c != EOF)
	{
		if (c == '>')
			fprintf(bf_out, "i++;");
		else if (c == '<')
			fprintf(bf_out, "i--;");
		else if (c == '+')
			fprintf(bf_out, "arr[i]++;");
		else if (c == '-')
			fprintf(bf_out, "arr[i]--;");
		else if (c == '[')
			fprintf(bf_out, "while(arr[i]){");
		else if (c == ']')
			fprintf(bf_out, "}");
		else if (c == '.')
			fprintf(bf_out, "putchar(arr[i]);");
		else if (c == ',')
			fprintf(bf_out, "arr[i]=getchar();");


		c = getc(bf_code);
	}
	fprintf(bf_out, "return 0;}");
	system("gcc bf.c && rm -f bf.c");
	return (0);
}
