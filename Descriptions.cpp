#include <stdio.h>

#include "descriptions.h"
#include "headerInfo.h"

void printAndStoreHeader(FILE* wavFile, const char* wavName) {
    printf("Break down of file %s's header:\n\n", wavName);
    printf(">RIFF chunk descriptor (describes entire file):\n\n");

    describeBytesByString(4,
        "First four bytes:",
        "(should be RIFF)",
        wavFile
    );

    wavHeader.fullChunkSize = describeBytesByLittleEndian(4,
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

    wavHeader.fmtSubSize = describeBytesByLittleEndian(4,
        "Current subchunk size in bytes:",
        "(Should be 16)",
        wavFile
    );

    wavHeader.audioFormat = describeBytesByLittleEndian(2,
        "Audio format:",
        "(Should be 1; if not, data is compressed)",
        wavFile
    );

    wavHeader.channels = describeBytesByLittleEndian(2,
        "Audio channels:",
        "(1 = mono, 2 = stereo)",
        wavFile
    );

    wavHeader.sampleRate = describeBytesByLittleEndian(4,
        "Sample rate:",
        "(44100 samples per second is a common sample rate)",
        wavFile
    );

    wavHeader.byteRate = describeBytesByLittleEndian(4,
        "Byte rate:",
        "(Sample rate * channels * bits per sample (to come) divided by 8)",
        wavFile
    );

    wavHeader.blockAlign = describeBytesByLittleEndian(2,
        "Block align:",
        "(The number of bytes for one sample, all channels included)",
        wavFile
    );

    wavHeader.bitsPerSample = describeBytesByLittleEndian(2,
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

    wavHeader.bytesOfMusic = describeBytesByLittleEndian(4,
        "How many bytes of data:",
        "bytes",
        wavFile
    );

    wavHeader.wavFile = wavFile;

}