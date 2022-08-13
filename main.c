#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int a = 2;
    a = strcmp("add",argv[1]);
    printf("%d",a);
    return 0;
}
