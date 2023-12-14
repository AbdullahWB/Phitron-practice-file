#include <stdio.h>

void world(){
    printf("Starting world program\n");
    printf("Ending world program\n");
}

void hello(){
    printf("Starting hello program\n");
    world();
    printf("Ending hello program\n");
}

int main()
{
    printf("Starting main program\n");
    hello();
    printf("Ending main program\n");
    return 0;
}