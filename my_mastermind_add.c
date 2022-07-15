#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "my_mastermind.h"

#define MAX_INPUT_SIZE 128

static int compare_codes(char digit, char *input, int index);

char *create_secret()
{
    // set up return str that contains the code
    char* secretPtr = (char*)malloc(5 * sizeof(char));
    secretPtr[4] = '\0';
    
    // seed the random nbr generator for rand()
    srand(time(0));

    // fill the code with nbrs from 0 to 7, convert the int to char while doing it
    for (int i = 0; i < 4; i++)
    {
		int randNumber = (rand() % 8);
		secretPtr[i] = (randNumber + '0');
	}
	return secretPtr;
}

char *read_input()
{
    char *input = NULL;
    char buff[MAX_INPUT_SIZE];
    my_memset(buff, '\0', MAX_INPUT_SIZE - 1);

    read(0, buff, 5);
    buff[4] = '\0';

    // make 'quitting' possible
    if (my_strcmp(buff, "quit") == 0)
    {
        input = my_strdup(buff);
        return input;
    }

    for (int i = 0; i < 4; i++)
    {
        if ((buff[i] < '0' || buff[i] > '7'))
        {
            printf("Wrong input!\n");
            return NULL;
        }
    }
    input = my_strdup(buff);
    return input;
}

int analyze_input(char *input, char *code)
{
    int well = 0;
    int miss = 0;

    // check for well-placed pieces
    for (int i = 0; i < my_strlen(input); i++)
    {
        if (input[i] == code[i])
            well++;
    }

    // check for misplaced pieces
    for (int i = 0; i < my_strlen(code); i++)
    {
        // increase nbr of missed pieces if match between the two codes is found
        if (compare_codes(code[i], input, i))
            miss++;
    }
    // display game info
    if (well < 4)
    {
        printf("Well placed pieces: %d\n", well);
        printf("Misplaced pieces: %d\n", miss);
    }
    return well;
}

static int compare_codes(char digit, char *input, int index)
{
    // compare current digit of secret code to all of input
    for (int i = 0; i < my_strlen(input); i++)
    {
        if (digit == input[i] && index != i)  // if match is not in the same place, it's a 'missed' piece
            return 1;
    }
    return 0;
}

int my_strlen(char *string)
{
    int counter = 0;

    while (string[counter] != '\0')
        counter++;
        
    return counter;
}

char *my_strdup(char* str)
{
    char* dupStr;
    int len = my_strlen(str) + 1;

    dupStr = (char*)malloc(sizeof(char) * len);
    if (dupStr == NULL)
    {
        printf("malloc of size %d failed!\n", len);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        dupStr[i] = str[i];
        
    dupStr[len-1] = '\0'; 
    return dupStr;   
}

int my_strcmp(char *s1, char *s2)
{
    while (*s1)
    {
        // if characters differ, or end of the second string is reached
        if (*s1 != *s2)
            break;

        // move to the next pair of characters
        s1++;
        s2++;
        // return the ASCII difference after converting `char*` to `unsigned char*`
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}   

void my_memset(char *str, char c, int n)
{
    int i = 0;
    for (; i < n; i++)
        str[i] = c;
    
    str[i] = '\0';
}
