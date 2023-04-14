#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{

    pid_t child1 = fork(); // fork() creates child one process
    int status1;
    int status2;

    if(child1 == 0){ 
        printf("I am child one, my pid is: %d\n",getpid()); //Child One will produce its PID
    }
    else{
        waitpid(child1, &status1, 0); 
        pid_t child2 = fork();  // fork() creates child one process
        if (child2 == 0){
            printf("I am child two, my pid is: %d\n",getpid()); // Child Two will produce its PID
        }else{
            printf("I am the parent process: %d\n", getpid()); // parent process behavior
            waitpid(child2, &status2, 0);
            printf("Parent Process Terminated: %d\n", getpid());

        }
    }

    return 0;
}