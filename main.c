#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>



int cmd_init(char **args);

int main(int argc, char **argv)
{
    int error = 0;

    if(!strcmp("init",argv[1]))
    {
        error = cmd_init(argv);
    }


    return 0;
}


int cmd_init(char **args)
{
    short int error = 0;
    short int PathLengt = 128;
    short int counter = 0;
    char folder_name[7] = "/.gitt";



    char *location =  malloc(PathLengt*sizeof(char));

    if(getcwd(location, PathLengt) == NULL) return 1;


    for(;;)
    {
        counter = 0;
        for(int i=0; i<PathLengt;i++)
        {
            if(location[i] == '\0') counter++;
        }

        if(counter < 4)
        {
            location = (char*) realloc(location,PathLengt+=7);
            getcwd(location, sizeof(location));
        }
        else break;

    }


    strcpy(location+PathLengt-counter,folder_name);

    error = mkdir(location, 0777);

    return error;

}
