/*  To demonstrate the use of I/O system calls for file I/O(read, write, open, lseek)
        Name of the program: ioFile.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BufferSize 30

int main()
{
    int fd, n;
    char buffer[BufferSize], fname[BufferSize];

    printf("Enter filename: ");
    scanf("%s", fname);
    fd = open(fname, O_RDWR);
    printf("File descriptor is %d\n", fd);

    if (fd == -1)
    {
        printf("Failed to open file!\n");
        exit(0);
    }

    printf("Reading first 10 characters from file: \n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nSkipping 5 characters from current position: \n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nGoing 10 characters before the current position in the file: \n");
    lseek(fd, -10, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nGoing to 5th last character in the file: \n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);

    printf("\nGoing to 3rd character in the file: \n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n\n");

    return 0;
}
