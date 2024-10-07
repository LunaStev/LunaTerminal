#include <stdio.h>
#include <string.h>
#include "commands.h"

#define MAX_COMMAND_LENGTH 256
#define MAX_PATH_LEN 4096

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char arg[MAX_COMMAND_LENGTH];

    printf("Terminal started. Type 'exit' to quit.\n");

    while (1)
    {
        printf("$ ");
        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting terminal.\n");
            break;
        }

        if (strcmp(command, "ls") == 0)
        {
            list_files();
            continue;
        }

        if (sscanf(command, "cd %s", arg) == 1)
        {
            change_directory(arg);
            continue;
        }

        if (sscanf(command, "mkdir %s", arg) == 1)
        {
            make_directory(arg);
            continue;
        }

        if (sscanf(command, "rm %s", arg) == 1) {
            remove_file(arg);
            continue;
        }

        printf("Unknown command.\n");
    }
    return 0;
}