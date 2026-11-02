#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scene {
    char *text;
} Scene;

Scene create_scene(char *text) {

    Scene new_scene;
    new_scene.text = text;
    
    return new_scene;
}

int main(int argc, char *argv[]) {

    Scene test_scene = create_scene("Lorem Ipsun dolor sit.");

    FILE *file_stream = NULL;

    char *path = "scenes";
    if (argc > 1) {
        path = argv[1];
    }

    file_stream = fopen(path, "ab+");

    if (file_stream == NULL) {
        printf("Error: failed to open '%s'.", path);
    }


    fclose(file_stream);


    return 0;
}


// https://man7.org/linux/man-pages/man2/time.2.html