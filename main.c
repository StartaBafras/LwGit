#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define FOLDER_NAME_LENGHT 7

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
    char folder_name[FOLDER_NAME_LENGHT] = "/.gitt";
    char other_dir[5][12] = {"/branches","/objects","/refs","/refs/tags","/refs/heads"};



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
            location = (char*) realloc(location,PathLengt+=FOLDER_NAME_LENGHT);
            getcwd(location, sizeof(location));
        }
        else break;

    }


    strcpy(location+PathLengt-counter,folder_name);
    error = mkdir(location, 0777);

    strcpy(location+PathLengt-counter+FOLDER_NAME_LENGHT-1,other_dir[0]);
    error = mkdir(location, 0777);

    strcpy(location+PathLengt-counter+FOLDER_NAME_LENGHT-1,other_dir[1]);
    error = mkdir(location, 0777);

    strcpy(location+PathLengt-counter+FOLDER_NAME_LENGHT-1,other_dir[2]);
    error = mkdir(location, 0777);

    strcpy(location+PathLengt-counter+FOLDER_NAME_LENGHT-1,other_dir[3]);
    error = mkdir(location, 0777);

    strcpy(location+PathLengt-counter+FOLDER_NAME_LENGHT-1,other_dir[4]);
    error = mkdir(location, 0777);


    free(location);
    return error;

}
