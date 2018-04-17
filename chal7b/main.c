#include <stdio.h>

void echo() {
	char buffer[512];

	gets(buffer);
	printf(buffer);
	printf("\n\n");
}

int main() {
	while(1) {	
		echo();
	}
}
