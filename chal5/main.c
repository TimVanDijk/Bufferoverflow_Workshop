#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    volatile int (*fp)();
    char buffer[42];

    fp = 0;

    gets(buffer);

    if (fp) {
        printf("calling function pointer, jumping to 0x%08x\n", fp);
        fp();
    }
    else {
        printf("You failed to change the function pointer :(\n"); 
    }

    //Works around gcc's dead code elimination.
    //We didn't seed random, so rand() always returns 1804289383,
    //effectively making it a if(0) {}.
    if (rand() == 0x13371337) {
        printf("Succes!\n");
    }
}

