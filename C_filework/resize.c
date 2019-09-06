// Resizes a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize size infile outfile\n");
        return 1;
    }

    //take an int for the resizing scale
    int n = atoi(argv[1]);

    char *outfile = argv[3];

    //open input file. Give me a pointer to a file and call it inptr
    //do this because fopen needs a ptr to go to what to open
    //call this opened file 'infile' and open it to read
    //double check I wasn't given a pointer pointing to null accidentally
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file same as above
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    bf.bfSize = (bf.bfSize * n);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //store original value of biWidth to use in old padding equation
    int old_width = bi.biWidth;

    int old_height = bi.biHeight;


    //manipulate biwidth, bisizeimage for the moment
    bi.biWidth = (bi.biWidth * n);
    bi.biHeight = (bi.biHeight * n);
    bi.biSizeImage = (bi.biSizeImage * n);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // work out how many bytes of padding there are in the old original infile
    int old_padding = (4 - (old_width * sizeof(RGBTRIPLE)) % 4) % 4;

    //work out how much padding there should be in the new outfile
    int new_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int a = 0, biHeight = abs(old_height); a < biHeight; a++) //this is loop a
    {

        for (int b = 0; b < n; b++)//loop b
        {
                // iterate over pixels in scanline
                for (int c = 0; c < old_width; c++)//this is loop c
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    //write RGB triple to outfile, n times
                    for(int d = 0; d < n; d++)//loop d
                        {
                            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                        }//end of loop d

                }//end of loop c

                //add padding to outfile
                for (int k = 0; k < new_padding; k++)
                {
                    fputc(0x00, outptr);
                }

                // skip over padding in the infile
                fseek(inptr, old_padding, SEEK_CUR);

                //rewind in infile if I need to
                if (b < (n - 1))
                {
                    fseek(inptr, -(old_padding + (old_width * sizeof(RGBTRIPLE))), SEEK_CUR);
                }


        }//end of loop b

    }//end of loop a

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
