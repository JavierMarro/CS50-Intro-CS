#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb"); // rb rather than just r because we are reading raw data
    FILE *dst = fopen(argv[2], "wb"); // wb rather than just w because we are writing raw data

    BYTE b;
    // while loop down below:
    // condition-reading a byte, then the size of the byte, the step, which will be reading 1 byte till it reaches the last byte (which is 0)
    // action inside loop-writing a byte, then the size of the byte, the step, which will be writing 1 byte till it reaches the last byte (which is 0)
    while(fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}

// in terminal, use command cp source-file destination-file to open one file and copy it into another
