#include <time.h>
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

    int scene_count = 0;
    Scene scenes[70];

    // file stuff
    FILE *file_stream = NULL;

    char *path = "data/scenes.david";
    if (argc > 1) {
        path = argv[1];
    }

    file_stream = fopen(path, "ab+");
    if (file_stream == NULL) {
        printf("Error: fopen() failed.\n");
        return EXIT_FAILURE;
    }

    int num_read = fread(scenes, sizeof(Scene), 70, file_stream);
    printf("Read %d items to '%s'.\n", num_read, path);
    
    fclose(file_stream);

    
    for (int i = 0; i < num_read; i++) {
        printf("%d - %s\n", i, scenes[i].text);
    }

    return 0;
}


// https://man7.org/linux/man-pages/man2/time.2.html