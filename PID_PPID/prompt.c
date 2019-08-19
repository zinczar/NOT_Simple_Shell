q#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
int main()
{
        ssize_t read;
	char *buffer;
        size_t bufsize = 32;

        buffer = malloc(bufsize * sizeof(char));
        if( buffer == NULL)
        {
                perror("Unable to allocate buffer");
                exit(1);
        }
        printf("$");

	while ((read = getline(&buffer, &bufsize, stdin)) != -1) {
		printf("Retrieved line of length %zu :\n", read);
        printf("%s\n", buffer);
        return(0);
}
