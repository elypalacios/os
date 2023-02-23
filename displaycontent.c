#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int fd;
    ssize_t rd, wd;
    char buffer[128];
    int num_bytes=128;

    
    //checks to see if the proper arguments are there when compling the program
    if(argc !=2){
    printf("File parameter is missing\n");
    return 1;
    }

    //allows file to be passed 
    char *filename = argv[1];
    fd = open(filename, O_RDONLY);
  
    if (fd == -1){
        printf("Error Failed To Open");
        return 1;
    }
    else{
        printf("Open() successful\n");
    }
    
    
    while(rd = read(fd, buffer, num_bytes)>0){
        wd= write(STDOUT_FILENO, buffer, rd);
        if (wd!=rd){
            printf("Errorr");
        }
        else {
            printf("Able To READ/WRITE: %ld %s", rd, buffer);
        }
    }

    if(rd ==-1)
        printf("Failed To Read");
   
    close(fd);

    return 0;
}
