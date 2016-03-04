#include <windows.h>
#include <stdio.h>
#include <math.h>
//size of picture definition
#define WIDTH 256
#define HEIGHT 256
typedef unsigned char T_pict[WIDTH][HEIGHT][3];  //3D matrix for picture content - width x height x RGBcolor
typedef unsigned char T_color[3]; //vector for RGBcolor

//function for circle drawing to T_pict matrix
int draw_circle(int xcenter, int ycenter, int radius, int width, T_color color, T_pict picture)
{
   double ang;
   int start, stop, i, x, y;

   start = radius - width/2;
   stop = radius + width/2;

   for(i = start; i <= stop; i++)
       for (ang = 0; ang < 6.3; ang += 0.002)
       {
           x = i*sin(ang)+xcenter;
           y = i*cos(ang)+ycenter;
           picture[x][y][0] = color[0];
           picture[x][y][1] = color[1];
           picture[x][y][2] = color[2];
       }
   return 0;
}

int main()
{
    BITMAPFILEHEADER bmp_fh;
    BITMAPINFOHEADER bmp_ih;
    RGBTRIPLE bmp_rgb;
    T_pict my_pict;           //picture matrix
    T_color my_color;         //color vector
    FILE *fBMP;
    int v, h, c;

    fBMP = fopen("test.bmp", "wb"); //BMP file for writing

    //part for BMP headers definition
    bmp_fh.bfType =  19778; //BITMAPFILEHEADER specification
    bmp_fh.bfSize = WIDTH * HEIGHT * 3 + 54;
    bmp_fh.bfReserved1 = 0;
    bmp_fh.bfReserved2 = 0;
    bmp_fh.bfOffBits = 54;
    fwrite(&bmp_fh, sizeof(bmp_fh), 1, fBMP); //write BITMAPFILEHEADER

    bmp_ih.biSize = 40; //BITMAPINFOHEADER specification
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

    //white canvas inicialization
    for(h = 0; h < HEIGHT; h++)
        for (v = 0; v < WIDTH; v++)
           for (c = 0; c < 3; c++)
                my_pict[v][h][c] = 0xFF;

    //red circle with diameter 50 in the middle of picture
    my_color[0] = 0xFF; //red color
    my_color[1] = 0xFF;
    my_color[2] = 0x00;
    draw_circle((3*WIDTH)/9, (3*HEIGHT)/8, 35, 5, my_color, my_pict);

    //green circle with diameter 75 in the middle of picture
    my_color[0] = 0x00; //green color
    my_color[1] = 0xFF;
    my_color[2] = 0x00;
    draw_circle((6*WIDTH)/9, (3*HEIGHT)/8, 35, 5, my_color, my_pict);

    //blue circle with diameter 100 in the middle of picture
    my_color[0] = 0x00; //blue color
    my_color[1] = 0x00;
    my_color[2] = 0xFF;
    draw_circle((2*WIDTH)/10, (3*HEIGHT)/6, 35, 5, my_color, my_pict);

        //blue circle with diameter 100 in the middle of picture
    my_color[0] = 0x00; //blue color
    my_color[1] = 0x00;
    my_color[2] = 0x00;
    draw_circle((5*WIDTH)/10, (3*HEIGHT)/6, 35, 5, my_color, my_pict);

        //blue circle with diameter 100 in the middle of picture
    my_color[0] = 0xFF; //blue color
    my_color[1] = 0x00;
    my_color[2] = 0x00;
    draw_circle((8*WIDTH)/10, (3*HEIGHT)/6, 35, 5, my_color, my_pict);

    //part for rewriting of picture matrix to BMP file
    for(h = 0; h < HEIGHT; h++) //rows in bitmaps from bottom to top
    {
        for (v = 0; v < WIDTH; v++) //columns in bitmaps from left to right
        {
            bmp_rgb.rgbtRed = my_pict[v][h][0];
            bmp_rgb.rgbtGreen = my_pict[v][h][1];
            bmp_rgb.rgbtBlue = my_pict[v][h][2];
            fwrite(&bmp_rgb, sizeof(bmp_rgb), 1, fBMP);
        }
    }
    fclose(fBMP);
    return 0;
}
