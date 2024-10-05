#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_PATH_LEN 1024

void list_files()
{
    DIR *dir;
    struct dirent *entry;

    char cwd[MAX_PATH_LEN];
    getcwd(cwd, MAX_PATH_LEN);

    dir = opendir(cwd);
    if (dir == NULL)
    {
        perror("opendir");
        return;
    }

    printf("Listing files in directory: %s\n", cwd);
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

void change_directory(const char *path)
{
    if (chdir(path) != 0)
    {
        perror("chdir");
    } else
    {
        char cwd[MAX_PATH_LEN];
        getcwd(cwd, MAX_PATH_LEN);
        printf("Directory changed to: %s\n", cwd);
    }
}

void make_directory(const char *dirname)
{
#ifdef _WIN32
    if (mkdir(dirname) != 0)
    {
        perror("mkdir");
    } else
    {
        printf("Created directory: %s\n", dirname);
    }
#else
    if (mkdir(dirname, 0777) != 0)
    {
        perror("mkdir");
    } else
    {
        printf("Created directory directory: %s\n", dirname);
    }
#endif
}

void remove_file(const char *filename)
{
    if (remove(filename) != 0)
    {
        perror("remove");
    } else
    {
        printf("Removed file: %s\n", filename);
    }
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char arg[MAX_COMMAND_LENGTH];

    printf("Terminal started. Type 'exit' to quit.\n");

    while (1)
    {
        printf(">>> ");
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
            break;
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