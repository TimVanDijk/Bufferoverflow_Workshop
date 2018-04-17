#include <stdio.h>

void echo() {
	char buffer[512];
	printf("The buffer is at: %p\n", buffer);

	gets(buffer);
	printf(buffer);
	printf("\n\n");
}

int main() {
	while(1) {	
		echo();
	}
}
