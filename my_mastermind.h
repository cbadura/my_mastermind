#ifndef MY_MASTERMIND_H
#define MY_MASTERMIND_H

	/* 
	In this section (I mean, between #define and #endif), you should list functions
	used in a separate .c file. Write just function declarations without bodies.	
	*/

    char* create_secret();
    int analyze_input(char* input, char* code);
	char *read_input();
	int my_strlen(char *string);

#endif