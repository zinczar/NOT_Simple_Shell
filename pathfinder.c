#include "shell.h"

char *pathfinder(char *input)
{
	size_t i = 0, j = 0;
        char *test_path = _strdup(_getenv("PATH="));
	char *path_token = strtok(test_path, ":");
	char *token_array[100];
	char *concat_token = NULL;

	printf("%s\n", input);

	while (path_token != NULL)
	{
		token_array[i++] = path_token;
		path_token = strtok(NULL, ":");
	}
	token_array[i] = NULL;

	while (token_array[j])
	{
		printf("%s\n", token_array[j]);
		_strcpy(concat_token, token_array[j]);
                printf("%s\n", concat_token);
		_strcat(concat_token, "/");
                printf("%s\n", concat_token);
		_strcat(concat_token, input);
                printf("%s\n", concat_token);
                _strcat(concat_token, "\0");
		printf("%s\n", concat_token);
		j++;
/*		if (access(concat_token, F_OK) == 0)
		return(concat_token);*/
	}

	return (input);
}
