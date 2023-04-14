#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>



int main(int argc, char*argv[]){

    int des1, des2; // two file descriptor being intialized
    char *destination1 = argv[1];
    char *destination2 = argv[2];

    // checks to see if the proper amounts of args are pass in command line
    if(argc != 3){
        perror("Not Enough Arguments");
        return 1;
    }

    // gives file descriptor read and write permission
    des1 = open(destination1, O_CREAT | O_RDWR, 0666 );
    des2 = open(destination2, O_RDWR |O_CREAT, 0666);

    //Check to see if the files were able to open
    if(des1 || des2 == -1){
        perror("Failed To Create");
        return 1;
    }

    //closing both file descriptors
    close(des1);
    close(des2);

}