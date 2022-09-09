#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
// definitions
#define BUFSIZE 512
typedef uint8_t BYTE;

// functions
bool find_JPEG(BYTE[]);
FILE* newfile(FILE*, char[], int, BYTE[]);

/**
 * main file
 */

int main(int argc, char* argv[])
{
    // check correct usage of program
    if(argc != 2)
    {
        fprintf(stderr, "Error: must be in format ./recover file.raw");
        return 1;
    }

    // open file
    char* input = argv[1];
    FILE* infile = fopen(input, "r");


    // check file is in right format
    if (infile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", input);
        return 2;
    }

/** 
 * run program with infile to restore JPGs
 */

    // declare variables
    BYTE buffer[BUFSIZE];
    int JPEG_counter = 0;
    char filename [8];
    FILE* img = NULL;
    img = newfile(img, filename, JPEG_counter, buffer);

    // enter while loop to run  (fread returns >0 if running)
    while(!feof(infile) && fread(&buffer, BUFSIZE, 1, infile) == true)
    {
        //  If start of new image identified
        if(find_JPEG(buffer) == true)
            {
                    // close current file
                    fclose(img);

                    // start new file
                    img = newfile(img, filename, JPEG_counter, buffer);
                    JPEG_counter++; 
            }

        // if not the start of a new image    
        if(find_JPEG(buffer) == false)
        {
            //if no image already started
            if(JPEG_counter == 0)
            {
                continue;
            }

            // if already writing a file
            else
            {
                fwrite(buffer, 1, BUFSIZE, img);   
            }
        }

    }  

    if(feof(infile))
    {
        fclose(img);
        fclose(infile);
    }

    return 0;   
}


/** 
 * declare functions for program to use
 */

bool find_JPEG(BYTE buffer[])
{
    // determine if new JPEG present?
    if  (buffer[0] == 0xff && 
        buffer[1] == 0xd8 &&
        buffer[2]== 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
        {
            return true;
        }

        else
        {
            return false;
        }
}

/**
 * create new file
 */

FILE* newfile(FILE* img, char filename[], int JPEG_counter, BYTE buffer[])
{
    sprintf(filename, "%03i.jpg", JPEG_counter);
    img = fopen(filename, "w");
    fwrite(buffer, 1, BUFSIZE, img);
    return img;
}