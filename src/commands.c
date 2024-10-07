#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <direct.h> // _getcwd() 사용을 위한 헤더
#define getcwd _getcwd
#define mkdir _mkdir
#else
#include <unistd.h>
#include <dirent.h>
#endif

#define MAX_COMMAND_LENGTH 256
#define MAX_PATH_LEN 4096

void list_files() {
#ifdef _WIN32
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    char cwd[MAX_PATH_LEN];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return;
    }

    // 현재 디렉터리에서 모든 파일 찾기
    char search_path[MAX_PATH_LEN];
    snprintf(search_path, sizeof(search_path), "%s\\*", cwd);

    hFind = FindFirstFile(search_path, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        perror("FindFirstFile");
        return;
    }

    printf("Listing files in directory: %s\n", cwd);
    do {
        printf("%s\n", findFileData.cFileName);
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
#else
    DIR *dir;
    struct dirent *entry;

    char cwd[MAX_PATH_LEN];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return;
    }

    dir = opendir(cwd);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing files in directory: %s\n", cwd);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
#endif
}

void change_directory(const char *path) {
    if (chdir(path) != 0) {
        perror("chdir");
    } else {
        char cwd[MAX_PATH_LEN];
        getcwd(cwd, MAX_PATH_LEN);
        printf("Directory changed to: %s\n", cwd);
    }
}

void make_directory(const char *dirname) {
#ifdef _WIN32
    if (mkdir(dirname) != 0) {
        perror("mkdir");
    } else {
        printf("Created directory: %s\n", dirname);
    }
#else
    if (mkdir(dirname, 0777) != 0) {
        perror("mkdir");
    } else {
        printf("Created directory: %s\n", dirname);
    }
#endif
}

void remove_file(const char *filename) {
    if (remove(filename) != 0) {
        perror("remove");
    } else {
        printf("Removed file: %s\n", filename);
    }
}
