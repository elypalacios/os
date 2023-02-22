#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main (int argc, char* argv[])
{
    int fd;
    fd = open(argv[1],O_CREAT|O_RDWR|0644);

    if(fd == -1){
        printf("\n FAILED TO CREATE");
        printf("%d",fd);
        return 1;
    }
    else{
            printf("\n SUCCESSFULLY CREATED %d", fd);
            
        }
    return 0;
}