#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    pid_t child1 = fork();
    int status1, status2;

    if (child1 == 0) {
        printf("child one successfully forked %d\n", getpid());
        char *args[] = {"./Prcs_P1", NULL}; 
        execv(args[1], args);
    } else {
        waitpid(child1, &status1, 0);
        pid_t child2 = fork();  // fork() creates child two process
        if (child2 == 0) {
            printf("child two successfully forked %d\n", getpid()); // Child Two will produce its PID
            char *args[] = {"./Prcs_P2", NULL};  
            execv(args[2], args); // needs both files two create both children
        } else {
            printf("I am the parent process: %d\n", getpid()); // parent process behavior
            waitpid(child2, &status2, 0);
            printf("Parent Process Terminated: %d\n", getpid());
        }
    }
    return 0;
}