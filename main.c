#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "headerInfo.h"

int main(int argc, char** argv) {
    /* arg processing */
    printf("Hello world!\n");

    if (argc == 1) {
        printf("Invalid Arguements\n");
        printf("Usage: %s [...].wav\n", argv[0]);
        exit(1);
    }

    FILE* wavFile = fopen(argv[1], "rb");
    char* wavName = argv[1];

    if (wavFile == NULL) {
        printf("File %s failed to open\n", argv[1]);
        exit(2);
    }


    /* Header anaylsis */

    printf("Break down of file %s's header:\n\n", wavName);
    printf(">RIFF chunk descriptor (describes entire file):\n\n");

    describeBytesByString(4,
        "First four bytes:",
        "(should be RIFF)",
        wavFile
    );

    describeBytesByLittleEndian(4,
        "The rest of the file's size (total file size in bytes minus 8):",
        "bytes",
        wavFile
    );

    describeBytesByString(4,
        "Next four bytes:",
        "(should be WAVE)",
        wavFile
    );

    printf(">fmt sub chunk (describes data format)\n\n");

    describeBytesByString(4,
        "Format subchunk first four bytes:",
        "(should be \"fmt \")",
        wavFile
    );

    describeBytesByLittleEndian(4,
        "Current subchunk size in bytes:",
        "(Should be 16)",
        wavFile
    );

    describeBytesByLittleEndian(2,
        "Audio format:",
        "(Should be 1; if not, data is compressed)",
        wavFile
    );

    describeBytesByLittleEndian(2,
        "Audio channels:",
        "(1 = mono, 2 = stereo)",
        wavFile
    );

    describeBytesByLittleEndian(4,
        "Sample rate:",
        "(44100 samples per second is a common sample rate)",
        wavFile
    );

    describeBytesByLittleEndian(4,
        "Byte rate:",
        "(Sample rate * channels * bits per sample (to come) divided by 8)",
        wavFile
    );

    describeBytesByLittleEndian(2,
        "Block align:",
        "(The number of bytes for one sample, all channels included)",
        wavFile
    );

    describeBytesByLittleEndian(2,
        "Bits per sample:",
        "The ammount of bits in one sample",
        wavFile
    );

    printf(">DATA subchunk\n\n");

    describeBytesByString(4,
        "Data subchunk first four bytes",
        "(should be data)",
        wavFile
    );

    describeBytesByLittleEndian(4,
        "How many bytes of data:",
        "bytes",
        wavFile
    );

    printf("The rest of the file is the music\n");

    printf("\nHello sucess!");
    return 0;
}
