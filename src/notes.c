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
    Scene *scenes;

    // add a scene
    scenes = realloc(scenes, sizeof(Scene) * (scene_count + 1));
    scenes[scene_count] = create_scene("Hello");
    scene_count += 1;
    
    // add a scene
    scenes = realloc(scenes, sizeof(Scene) * (scene_count + 1));
    scenes[scene_count] = create_scene("Goodbye");
    scene_count += 1;


    // file stuff
    FILE *file_stream = NULL;

    char *path = "scenes.david";
    if (argc > 1) {
        path = argv[1];
    }

    file_stream = fopen(path, "ab+");
    if (file_stream == NULL) {
        printf("Error: fopen() failed.\n");
        return EXIT_FAILURE;
    }

    int num_written = fwrite(scenes, sizeof(Scene), scene_count, file_stream);
    printf("Written %d items to '%s'.\n", num_written, path);
    
    printf("%s\n", argv[2]);

    fclose(file_stream);

    return 0;
}


// https://man7.org/linux/man-pages/man2/time.2.html