#include <time.h>
#include <stdio.h>

typedef struct Note {
    char *text[256];
} Note;

int main() {


    time_t tempo = time(NULL);
    // same as
    /*
    time_t tempo;
    time(&tempo);
    */
    
    printf("%ld\n", (long) tempo);

    return 0;
}


// https://man7.org/linux/man-pages/man2/time.2.html