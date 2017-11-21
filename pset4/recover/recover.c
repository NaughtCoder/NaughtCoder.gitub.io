#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];
    FILE *in_ptr = fopen(infile, "r");
    FILE *img = NULL;

    if(in_ptr == NULL)
    {
        fprintf(stderr, "Could not open %s\n", infile);
        return 2;
    }

    uint8_t buffer[512];
    char filename[8];
    int jpeg_found = 0; //0 for false and 1 for true
    int file_count = 0;


    while(fread(buffer, 1, 512, in_ptr) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(jpeg_found == 0)
            {
                sprintf(filename, "%03i.jpg", file_count);
                img = fopen(filename, "w");

                file_count++;
                jpeg_found = 1;
            }
            else if(jpeg_found == 1)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", file_count);
                img = fopen(filename, "w");
                file_count++;
            }

        }

        if(jpeg_found == 1)
            fwrite(buffer, 1, 512, img);
    }

    fclose(img);
    fclose(in_ptr);
    return 0;

}