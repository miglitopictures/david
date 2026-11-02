#include <stdlib.h>
#include <stdio.h>

int main(int argument_count, char **arguments) {

	FILE *file_stream;
	char *line = NULL;
	size_t size = 0;

	// get path to file
	char *path = "hello.txt";
	if (argument_count > 1) {
		path = arguments[1];
	}

	// open file and check if it worked
	file_stream = fopen(path, "r");
	if (file_stream == NULL) {
		printf("Error: failed to open file '%s'.\n", path);
		return 1;
	}

	// read file and printf it to stdou
	int line_number = 1;
	while (getline(&line, &size, file_stream) != -1) {
		printf("%3d | %s", line_number, line);
		line_number += 1;
	}
	
	printf("\n");

	// close stuff
	fclose(file_stream);
	free(line);
	return 0;
}


// material:
// https://man7.org/linux/man-pages/man3/getline.3.html