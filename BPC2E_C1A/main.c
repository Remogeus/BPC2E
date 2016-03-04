#include <windows.h>
#include <stdio.h>
#include <math.h>
//size of picture definition
#define WIDTH 512
#define HEIGHT 512

int main()
{
    BITMAPFILEHEADER bmp_fh;
    BITMAPINFOHEADER bmp_ih;
    RGBTRIPLE bmp_rgb;
    FILE *fBMP;
    int h, v;

    fBMP = fopen("test.bmp", "wb"); //BMP file for writing

    //part for BMP headers definition
    bmp_fh.bfType =  19778; // BITMAPFILEHEADER specification
    bmp_fh.bfSize = WIDTH * HEIGHT * 3 + 54;
    bmp_fh.bfReserved1 = 0;
    bmp_fh.bfReserved2 = 0;
    bmp_fh.bfOffBits = 54;
    fwrite(&bmp_fh, sizeof(bmp_fh), 1, fBMP); //write BITMAPFILEHEADER

    bmp_ih.biSize = 40; // BITMAPINFOHEADER specification
    bmp_ih.biWidth = WIDTH;
    bmp_ih.biHeight = HEIGHT;
    bmp_ih.biPlanes = 1;
    bmp_ih.biBitCount = 24;
    bmp_ih.biCompression = 0;
    bmp_ih.biSizeImage = WIDTH * HEIGHT * 3;
    bmp_ih.biXPelsPerMeter = 0;
    bmp_ih.biYPelsPerMeter = 0;
    bmp_ih.biClrUsed = 0;
    bmp_ih.biClrImportant = 0;
    fwrite(&bmp_ih, sizeof(bmp_ih), 1, fBMP); //write BITMAPINFOHEADER

    //part for bitmap content definition
    for(h = 0; h < HEIGHT; h++)  //rows in bitmaps from bottom to top
    {
        for (v = 0; v < WIDTH; v++) //columns in bitmaps from left to right
        {
            /*
            bmp_rgb.rgbtRed = 0x00;
            bmp_rgb.rgbtGreen = (h+v)%256;
            h%256 - 2 pruhy delene horizontalne
            v%256 - 2 pruhy delene vertikalne
            v%128 - 4 pruhy s jasem 0 - 127
            (2*v)%256 - 4 pruhy s plnym jasem
            (v/2)%256 - jen prechod
            sinus hodnoty - vlny kopirujici funkci sinus
            bmp_rgb.rgbtBlue = 0x00;
            fwrite(&bmp_rgb, sizeof(bmp_rgb), 1, fBMP);*/
            if((h < (HEIGHT/2)) && (v < (WIDTH/2)))
            {
                bmp_rgb.rgbtRed = (h+v)%256;
                bmp_rgb.rgbtGreen = (h+v)%256;
                bmp_rgb.rgbtBlue = 0x00;
            }
            else if((h < (HEIGHT/2)) && (v < (WIDTH)))
            {
                bmp_rgb.rgbtRed = 0x00;
                bmp_rgb.rgbtGreen = (2*h)%256;
                bmp_rgb.rgbtBlue = 0x00;
            }
            else if((h < (HEIGHT)) && (v < (WIDTH/2)))
            {
                bmp_rgb.rgbtRed = (2*(h+v))%256;
                bmp_rgb.rgbtGreen = 0x00;
                bmp_rgb.rgbtBlue = (2*(h+v))%256;
            }
            else
            {
                bmp_rgb.rgbtRed = (2*v)%256;
                bmp_rgb.rgbtGreen = (2*v)%256;
                bmp_rgb.rgbtBlue = (2*v)%256;
            }


            fwrite(&bmp_rgb, sizeof(bmp_rgb), 1, fBMP);

        }
    }
    fclose(fBMP);
    return 0;
}
