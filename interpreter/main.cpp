#include <functional>
#include <iostream>
#include <map>
void brainfuck(char *command) {
	int brackets;
	std::map<int, char> array;
	int i;
	int brc = 0;
	std::map<char, std::function<void(void)>> cmd{
	    {'>', [&i]() { ++i; }},
	    {'<', [&i]() { --i; }},
	    {'+', [&array, &i]() { ++array[i]; }},
	    {'-', [&array, &i]() { --array[i]; }},
	    {'[',
	     [&command, &array, &i,&brc]() {
		     if (array[i] != 0) return;
		     brc++;
		     while (brc) {
			     ++command;
			     if (*command == '[') ++brc;
			     if (*command == ']') --brc;
		     }
	     }},
	    {']',
	     [&command, &array, &i,&brc]() {
		     if (array[i] == 0) return;
		     while (brc) {
			     --command;
			     if (*command == '[') --brc;
			     if (*command == ']') ++brc;
		     }
	     }},
	    {'.', [&array, &i]() { std::cout << array[i]; }},
	    {',', [&array, &i]() { std::cin >> array[i]; }}};

	while (*command != '\0') cmd[*(command++)]();
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Give one argument as code\n");
		return (0);
	}
	brainfuck(argv[1]);
	return (0);
}
