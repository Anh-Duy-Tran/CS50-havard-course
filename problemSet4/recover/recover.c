#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int BLOCK_SIZE = 512;

typedef uint8_t BYTE;

bool is_signature(uint8_t *begin){
    return (begin[0] == 0xff && begin[1] == 0xd8 && begin[2] == 0xff && begin[3] / 16 == 14);
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("ussage: ./recover <inputfilename.raw>\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL){
        printf("cannot open file \n");
        return 2;
    }

    BYTE block[BLOCK_SIZE];

    char outfile_name[50][20];

    for (int i = 0; i < 50; i++)
    {
        char tmp[20] = "outfile00.jpg";

        tmp[8] += (i + 1) % 10;
        tmp[7] += (i + 1) / 10;

        strcpy(outfile_name[i], tmp);
    }

    int i = 0;
    int count = 0;
    FILE *outfile = fopen(outfile_name[count], "w");

    while (fread(&block, sizeof(block), 1, infile)){
        if (is_signature(block))
        {
            while(true){
                fwrite(&block, sizeof(block), 1, outfile);
                if(!fread(&block, sizeof(block), 1, infile))
                    return 0;
                if (is_signature(block))
                {
                    count++;
                    outfile = fopen(outfile_name[count], "w");
                    //break;
                }
            }
        }
    }

    
    return 0;
}