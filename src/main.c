#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_PATH_LEN 1024

int main()
{
    char command[MAX_COMMAND_LENGTH];

    printf("Terminal started. Type 'exit' to quit.\n");

    while (1)
    {
        printf(">>> ");

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            printf("Error reading command.\n");
            continue;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting terminal.\n");
            break;
        }

        int result = system(command);
        if (result == 1)
        {
            printf("Command execution failed.\n");
        }
    }
}