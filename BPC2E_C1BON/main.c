#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    BITMAPFILEHEADER bmp_fh;
    BITMAPINFOHEADER bmp_fi;
    RGBTRIPLE bmp_rgb;

    int i, j;
    unsigned char Red, Green, Blue, Avg;

    FILE *TPR, *CHM; // CHM - Color height map

    TPR = fopen("TPR.bmp", "rb");
    CHM = fopen(argv[1], "wb");

    fread(&bmp_fh, sizeof(bmp_fh), 1, TPR);
    fwrite(&bmp_fh, sizeof(bmp_fh), 1, CHM);

    fread(&bmp_fi, sizeof(bmp_fi), 1, TPR);
    fwrite(&bmp_fi, sizeof(bmp_fi), 1, CHM);
    size_t padd = 0;
    if((bmp_fi.biWidth * 3) % 4)  // padding test
        padd = 4 - (bmp_fi.biWidth * 3) % 4;


    for(i = 0; i < bmp_fi.biHeight; i++)
    {
        for(j = 0; j < bmp_fi.biWidth; j++)
        {
            fread(&bmp_rgb, sizeof(bmp_rgb),1, TPR);
            Red = bmp_rgb.rgbtRed;
            Green = bmp_rgb.rgbtGreen;
            Blue = bmp_rgb.rgbtBlue;

            Avg = (Red + Green + Blue)/3;
            int test = Avg;
            if(test <= atoi(argv[2]))
            {
                bmp_rgb.rgbtRed = 0x00;
                bmp_rgb.rgbtGreen = 0x00;
                bmp_rgb.rgbtBlue = 0xFF;
            }
            else
            {
                bmp_rgb.rgbtRed = 0x00;
                bmp_rgb.rgbtGreen = 0xFF;
                bmp_rgb.rgbtBlue = 0x00;
            }
            fwrite(&bmp_rgb, sizeof(bmp_rgb), 1, CHM);
        }
        if(padd != 0)
        {
            fread(&bmp_rgb, padd, 1, TPR);
            fwrite(&bmp_rgb, padd, 1, CHM);
        }
    }

    fclose(TPR);
    fclose(CHM);

    return 0;
}
