#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char* argv[])

{
    char* filepath = argv[1]; //allows the file to get passed through the command line
    int returnval;

    // Check file existence
    returnval = access (filepath, F_OK); // F_OK checks for files existences
    if (returnval == 0)
        printf ("\n %s exists\n", filepath);
    else {
        if (errno == ENOENT)
        printf ("%s does not exist\n", filepath);
    else if (errno == EACCES)
        printf ("%s is not accessible\n", filepath);
    }

    // Check read access
    int read;
    read = access (filepath,R_OK); // We use R_OK flag to check for read permission

    if (read == 0) 
        printf ("\n %s You Have Access To Read \n", filepath);
    else {
        if (errno == ENOENT) 
        printf ("%s does not exist\n", filepath);
    else if (errno == EACCES) //error occurs if access permission is denied
        printf ("%s is not accessible\n", filepath);
    }

    // Check write access
    int write;
    write = access (filepath, W_OK);
    if (write == 0)
        printf ("\n %s You Can Write ! \n" , filepath);
    else {
        if (errno == ENOENT)//error if file does not exist
        printf ("%s does not exist\n", filepath);
    else if (errno == EACCES)
        printf ("%s is not accessible\n", filepath);
    }
    
    return 0;
}