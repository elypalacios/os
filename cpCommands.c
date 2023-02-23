#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main (int argc, char*argv[]){


    if(argc !=3){
    printf("File parameter is missing\n");
    return 1;
    }

    int fd, nd;
    ssize_t rd, wd;
    char buffer[128];
    int num_bytes=128;

    char *Filename = argv[1];
    char *NewDestination = argv[2];
    fd = open(Filename,O_RDONLY);

    if(fd == -1){
        printf("Failed to Open()");
        return 1;
    }
    else{
        printf("Open() was successful\n");
    }

    nd = open(NewDestination, O_CREAT| O_RDWR);
    if (nd == -1){
        printf("Failed to Create");
    }


    while(rd = read(fd, buffer, num_bytes)>0){
        wd= write(nd, buffer, rd);
        if (wd!=rd){
            printf("Error");
        }
        
    } 

    if(rd ==-1)
        printf("Failed To Read");
   
    close(fd);
    close(nd);

    return 0;
}