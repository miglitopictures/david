#include <stdlib.h>
#include <stdio.h>

int main(int argument_count, char **arguments) {

	FILE *writing_stream;
	
	// get path to file
	char *path;
	if (argument_count == 1) {
		printf("Error: did not inform filename.\n");
		return 1;
	}
	path = arguments[1];
	
	// try to open file and check if exsts
	FILE *reading_stream = NULL;
	reading_stream = fopen(path, "r");
	if (reading_stream != NULL) {
		printf("Error: file '%s' already exists.\n", path);
		fclose(reading_stream);
		return 1;
	}

	// create file and check if it worked
	writing_stream = fopen(path, "w+");
	if (writing_stream == NULL) {
		printf("Error: failed to open file '%s'.\n", path);
		return 1;
	}

	// close stuff
	fclose(writing_stream);
	return 0;
}


// material:
// https://man7.org/linux/man-pages/man3/getline.3.html