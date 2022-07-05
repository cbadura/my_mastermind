#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "my_mastermind.h"

void game(char* code, int attempts);

int main(int ac, char** av)
{
    char* ptr = (char*)malloc(5 * sizeof(char));
    ptr = NULL;
    int attempts = 10;

    // parse arguments
    if(ac == 1) ptr = create_secret();
    
    if(ac > 1)
    {
        // if only option -t is chosen
        if(strcmp(av[1], "-t") == 0)
        {
            ptr = create_secret();
            if(av[2])
            {
                if(atoi(av[2]) > 0 && atoi(av[2]) < 10)
                    attempts = atoi(av[2]);
            }
        }
        // if only option -c is chosen
        if(strcmp(av[1], "-c") == 0)
        {
            if(av[2]) ptr = av[2];
            else ptr = create_secret();
        }
        // if both options are chosen
        if(strcmp(av[1], "-ct") == 0)
        { 
            if(av[2]) ptr = av[2];
            else ptr = create_secret();
            if(av[3])
            {
                if(atoi(av[3]) > 0 && atoi(av[3]) < 10)
                    attempts = atoi(av[3]);
            }
        }
    }
    game(ptr, attempts);
    
    // check if create_secret() has been called, thus if malloc'd ptr is used – then free it
    if(ac == 1 || (strcmp(av[1], "-t") == 0 && av[2]) || ((strcmp(av[1], "-ct") == 0) && !av[2])) 
        free(ptr);
    return 0;
}

void game(char* code, int attempts)
{
    int round = 0;
    char buf[5];
    char *input;

    printf("Will you find the secret code?\n");
    
    for(int i = 0; i < attempts; i++) {
        printf("---\n");
        printf("Round %d\n", round);

        input = read_input();

        int well = analyze_input(input, code);
        if(well == 4) {
            printf("Congrats! You did it!\n");
            break;
        }
        round++;
    }
}