// a script writting app

// write a new scene
// > david "Lorem ipsum"

// show all scenes already written
// > david

// delete the last scene
// > david -regret

// by miguel duarte

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#define MAX_CHARS 256

typedef struct Scene {
    char text[MAX_CHARS];
} Scene;

int main(int argc, char *argv[]) {

    char *path = "./scenes.david";
    FILE *file_stream = NULL;

    file_stream = fopen(path, "ab+");
    if (file_stream == NULL) {
        printf("Error: fopen() failed.\n");
        return EXIT_FAILURE;
    }

    // has argument
    // check if its a command (-) or its a new scene ("")
    if (argc > 1) {
        if (*argv[1] == '-') {
            argv[1] = (argv[1] + 1); // discard the dash and compare to known operations
            // regret - deletes last item
            if (*argv[1] == 'r' || strcmp(argv[1], "regret") == 0) {

                // find "slice point", end of file minus size of a scene
                fseek(file_stream, sizeof(Scene) * -1, SEEK_END);
                long slice_point = ftell(file_stream);
                
                // get file decriptor
                int file_descriptor = fileno(file_stream);
                
                if (ftruncate(file_descriptor, slice_point) != 0) {
                    printf("Error: ftruncate() failed.\n");
                }
            }
            // progress - shows progress
            else if (*argv[1] == 'p' || strcmp(argv[1], "progress") == 0) {

                // get the size of the file with fseek and ftell
                fseek(file_stream, 0, SEEK_END);
                long size_of_file = ftell(file_stream);
                // 'derive' scene count
                int current_scene_count = size_of_file / sizeof(Scene);
                // show it
                printf("%02d out of 70.\n", current_scene_count);
            } else {
                printf("'%s' is not a command.\n", argv[1]);
            }
        }
        else {
            // create a scene with the argument as .text
            Scene new_scene;
            strncpy(new_scene.text, argv[1], MAX_CHARS - 1);
            // save it to the file
            int num_written = fwrite(&new_scene, sizeof(Scene), 1, file_stream);
            printf("Written %d item to '%s'.\n", num_written, path);
        }
    }
    // no arguments (show what we already have)
    else {
        Scene scenes[128];
        // read scenes from file
        fseek(file_stream, 0, SEEK_SET);
        int num_read = fread(scenes, sizeof(Scene), 128, file_stream);
        // print scenes
        for (int i = 0; i < num_read; i++) {
            printf("\x1B[1m%2d\x1B[0m - %s\n", i+1, scenes[i].text);
        }
    }
    
    
    fclose(file_stream);

    return 0;
}


// https://man7.org/linux/man-pages/man2/time.2.html
// https://en.cppreference.com/c/io/fwrite
// https://man7.org/linux/man-pages/man3/fileno.3.html
// https://en.cppreference.com/c/io/fseek
// https://man7.org/linux/man-pages/man3/ftruncate.3p.html