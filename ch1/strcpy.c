#include <stdio.h>
#include <stdlib.h>

char *strcpy(char *dst, char *src);

int main(int argc, char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Error: expected argument\n");
		exit(EXIT_FAILURE);
	}

	char newString[100];

	strcpy(newString, argv[1]);

	printf("%s\n", newString);

	return EXIT_SUCCESS;
}

char *strcpy(char *dst, char * src) {
	char *s = dst;

	while(*dst++ = *src++);

	return s;
}