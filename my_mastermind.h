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
	char *my_strdup(char* str);
	void my_memset(char *str, char c, int n);
	int my_strcmp(char *s1, char *s2);

#endif
