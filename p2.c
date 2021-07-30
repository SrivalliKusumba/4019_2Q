#include<stdio.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define SIZE 10


int *count;
char buff[SIZE];


int main(int argc, char const *argv[])
{
    int shmd;

    shmd = shm_open("/usr/share/dictionary", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    
    ftruncate(shmd,SIZE * sizeof(char) );

    *buff = mmap(NULL,SIZE*sizeof(char),PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0);

    
    while(1)
    {
        printf("%s",buff);

    }

    return 0;
}

