// a script writting app

// write a new scene
// > david "Lorem ipsum"

// show all scenes already written
// > david

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

typedef struct Scene {
    char text[MAX_CHARS];
} Scene;

Scene create_scene(char *text) {
    Scene new_scene;
    strncpy(new_scene.text, text, MAX_CHARS - 1);
    return new_scene;
}

int main(int argc, char *argv[]) {

    // file stuff
    char *path = "./scenes.david";
    FILE *file_stream = NULL;

    file_stream = fopen(path, "ab+");
    if (file_stream == NULL) {
        printf("Error: fopen() failed.\n");
        return EXIT_FAILURE;
    }

    // has argument (add a new scene with argument as text)
    if (argc > 1) {
        if (*argv[1] == '-') {
            argv[1] = (argv[1] + 1); // discard the hifen and compare to known operations
            printf("- identified a command (%s)\n", argv[1]);
        }
        else {
            Scene new_scene;
            strncpy(new_scene.text, argv[1], MAX_CHARS - 1);
            int num_written = fwrite(&new_scene, sizeof(Scene), 1, file_stream);
            printf("Written %d item to '%s'.\n", num_written, path);
        }
    }
    // no arguments (show what we already have)
    else {
        Scene scenes[128];
        fseek(file_stream, 0, SEEK_SET);
        int num_read = fread(scenes, sizeof(Scene), 128, file_stream);
        for (int i = 0; i < num_read; i++) {
            printf("\x1B[1m%2d\x1B[0m - %s\n", i+1, scenes[i].text);
        }
    }
    
    
    fclose(file_stream);

    return 0;
}


// https://man7.org/linux/man-pages/man2/time.2.html
// https://en.cppreference.com/c/io/fwrite
// https://man7.org/linux/man-pages/man1/date.1.html
