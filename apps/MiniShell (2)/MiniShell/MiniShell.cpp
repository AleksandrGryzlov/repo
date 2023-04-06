
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
struct command {
    char* cmd;
    char* argv[10];
    int argc;
    char* infile;
    char* outfile;
};
int main() {
    char line[100];
    struct command cmd;
    char* token;
    int i;
    int fd;
    int pid;
    int status;
    while (1) {
        printf("$ ");
        fgets(line, 100, stdin);
        line[strlen(line) - 1] = '\0';
        if (strcmp(line, "exit") == 0) {
            exit(0);
        }
        token = strtok(line, " ");
        cmd.cmd = token;
        cmd.argc = 0;
        token = strtok(NULL, " ");
        while (token != NULL) {
            if (strcmp(token, "<") == 0) {
                token = strtok(NULL, " ");
                cmd.infile = token;
            }
            else if (strcmp(token, ">") == 0) {
                token = strtok(NULL, " ");
                cmd.outfile = token;
            }
            else {
                cmd.argv[cmd.argc] = token;
                cmd.argc++;
            }
            token = strtok(NULL, " ");
        }
        cmd.argv[cmd.argc] = NULL;
        pid = fork();
        if (pid == 0) {
            if (cmd.infile != NULL) {
                fd = open(cmd.infile, O_RDONLY);
                dup2(fd, 0);
                close(fd);
            }
            if (cmd.outfile != NULL) {
                fd = creat(cmd.outfile, 0644);
                dup2(fd, 1);
                close(fd);
            }
            execvp(cmd.cmd, cmd.argv);
            printf("Command not found\n");
            exit(0);
        }
        else {
            wait(&status);
        }
    }
}
