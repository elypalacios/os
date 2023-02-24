#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main (int argc, char*argv[]) {

    char *Filename = argv[1];  
    char *NewDestination = argv[2];

    //Checks to see if command line has the correct number of arguments
    if (argc != 3) {
    perror("Not Enough Arguments");        return 1;
    }

    int filed, newd; // old file descriptor and new file descriptor being intialized 
    ssize_t rd, wd; //storage for read() and write() 
    int size = 150;
    char buffer[size]; // creating buffer to store data from old file

    newd = open(NewDestination, O_CREAT | O_WRONLY | O_TRUNC, 0666);

    //Checks to see if the new file was opened successfully
    if (newd == -1) {
        perror("Failed To Open()");
        return 1;
    }


    filed = open(Filename, O_RDONLY, 0644);

    //Checks to see if the old file was opened successfully
    if (filed == -1) {
        perror("Failed to Open()");
        close(newd);
        return 1;
    }

    //Copies old file to new file
    while ((rd = read(filed, buffer, 100)) > 0) {
        for (int i=0; i<rd ; i++){ //created a for loop to check for "1" and changed them to "L"
        if(buffer[i]=='1'){
            buffer[i] ='l';
        }}
        
        //writing buffer to new file
        wd = write(newd, buffer, rd);
    
        //checks to see if number bytes from rd and wd matches
        if (wd != rd) {
            perror("Error");
            close(filed);
            close(newd);
            return 1;
        }
    }

    // continues to add "XYZ" until the end of the file. 
    // The end of the file has a size of 150

    for (int i=0; i<size ; i++){
        write(newd, "XYZ", 3) > 0;
    }

    // close the files
    if (close(filed) || close(newd)) {
        perror("close");
        return 1;
    }


    printf("File Copied.\n");

    return 0;
}