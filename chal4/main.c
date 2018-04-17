#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void win() {
    printf("Succes!\n");
}

int main() {
    volatile int (*fp)();
    char buffer[42];

    fp = 0;

    gets(buffer);

    if(fp) {
        printf("calling function pointer, jumping to 0x%08x\n", fp);
        fp();
    }
    else {
        printf("You failed to change the function pointer :(\n"); 
    }
}