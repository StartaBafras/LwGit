#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cmd_init(char args[]);

int main(int argc, char **argv)
{
    
    if(!strcmp("init",argv[1]))
    {
        cmd_init(argv);
    }


    return 0;
}

int cmd_init(char args[])
{
    FILE *file = NULL;

}
