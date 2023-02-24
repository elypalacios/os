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
        printf("File parameter is missing\n");
        return 1;
    }

    int filed, newd; //file descriptors (old and new)
    ssize_t rd, wd;
    const int size = 1024;
    char buffer[size]; // creating buffer to store data from old file

    newd = open(NewDestination, O_CREAT | O_WRONLY | O_TRUNC, 0666);

    //Checks to see if the new file was opened successfully
    if (newd == -1) {
        perror("Open");
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
    while ((rd = read(filed, buffer, size)) > 0) {
        wd = write(newd, buffer, rd);
        if (wd != rd) {
            perror("Error");
            close(filed);
            close(newd);
            return 1;
        }
    }

    // close the files
    if (close(filed) || close(newd)) {
        perror("close");
        return 1;
    }

    printf("File Copied.\n");

    return 0;
}