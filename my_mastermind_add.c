#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "my_mastermind.h"
#define MAX_ARRAY_SIZE 128

char *create_secret()
{
    char* secretPtr = (char*)malloc(5 * sizeof(char));
    srand(time(0));

    for (int i = 0; i < 4; i++)
    {
		int randNumber = (rand() % 8);
		secretPtr[i] = (randNumber + '0');
	}
    secretPtr[5] = '\0';

	return secretPtr;
}

char *read_input()
{
    char buff[MAX_ARRAY_SIZE];
    read(0, buff, 4);

    for (int i = 0; i < 4; i++)
    {
        if ((buff[i] < '0' || buff[i] > '8'))
        {
            printf("Wrong input!\n");
            read_input();
        }
    }
    char* ptr = buff;
    return ptr;
}

int analyze_input(char *input, char *code)
{
    int well, miss;
    // check for well-placed pieces
    well = 0;
    for(size_t i = 0; i < my_strlen(code); i++)
    {
        if(input[i] == code[i])
            well++;
    }
    // check for misplaced pieces
    miss = 0;
    for (size_t i = 0; i < my_strlen(code); i++)
    {
        for(int j = 1; j < 4; j++) {
            if(input[i] == code[i+j] || input[i] == code[i-j])
                miss++;
        }
    }
    // display game info
    if (well < 4) {
        printf("Well placed pieces: %d\n", well);
        printf("Misplaced pieces: %d\n", miss);
    }
    return well;
}

int my_strlen(char *string)
{
    int counter = 0;

    while(string[counter] != '\0')
        counter++;
        
    return counter;
}