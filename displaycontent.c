#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int fd; //file descriptor
    ssize_t rd, wd;
    int size=150; 
    char buffer[size]; //declaring buffer that will store data
    

    
    //checks to see if the proper arguments are there when compling the program
    if(argc !=2){
    perror("Not Enough Arguments");
    return 1;
    }

    //allows file to be passed 
    char *filename = argv[1];
    fd = open(filename, O_RDONLY);
  

    //checks  to see if file was opened successfully
    if (fd == -1){
        perror("Failed to Open()");
        return 1;
    }
    else{
        printf("Open() successful\n");
    }
    
    
    while(rd = read(fd, buffer, 150)>0){ //reads up to 150 bytes into buffer
        wd= write(STDOUT_FILENO, buffer, rd);  //writes the read() data in buffer to standard output
        if (wd!=rd){ //checks to see if the read number of bytes is the same as writes number of bytes
            perror("Error"); //if (rd and wd) are different error message will display
            close(fd);  
            return 1;}
        else{
            printf("%s" , buffer); // else print the data from buffer onto terminal
        }
    
    }

    if(rd ==-1){
        perror("Failed To read");
        return 1;
    }

    close(fd); //closing the file descriptor 
    return 0;
}
