#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "headerInfo.h"
#include "descriptions.h"
#include "samplePlay.h"

int main(int argc, char** argv) {
    /* arg processing */
    printf("Hello world!\n");

    if (argc == 1) {
        printf("Invalid Arguements - two required\n");
        printf("Usage: %s <...>.wav\n", argv[0]);
        exit(1);
    }

    FILE* wavFile = fopen(argv[1], "rb");
    char* wavName = argv[1];

    /* Command line options - just a prototype, this won't really implemented
     * properly until the end, so for now, they're useless
     */
    /* No really I shouldn't even have them here. The only ones you can have
     * is the output file, which needs to be provided for now. They're here
     * so I'll be reminded of them later
     */
    if (wavFile == NULL) {
        printf("File %s failed to open\n", argv[1]);
        exit(2);
    }
    else if (argc == 3 && argv[2][0] == '-' && argv[2][1] == 'h') {
        printf("Option descriptions:\n");
        printf("    -1 <output>.txt : print the first sample to file");
        printf("    -s <output>.txt : print a second of samples to file");
        exit(0);
    }
    else if (argc == 3 ) {
        printf("Incorrect ammount of arguements\n");
        printf("Options:\n");
        printf("    <input>.wav -1 <output>.txt\n");
        printf("    <input>.wav -s <output>.txt\n");
        exit(1);
    }
    else if (argc == 4) {


    }

    /* Header anaylsis */
    printAndStoreHeader(wavFile, wavName);

    /* poking around the bytes */
    //printf("Struct test: sample rate: %u\n", wavHeader.sampleRate);

    FILE* newFile = fopen("output.txt", "w");
    fprintSecondOfSamples(newFile);
    printOneSampleBytes();


    printf("The rest of the file is the music\n");

    printf("\nHello sucess!");
    return 0;
}
