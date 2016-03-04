#include <iostream>
#include <cmath>
#define BLOCK 219
#define STAR '*'
#define PLUS '+'
#define CIRCLET 'o'
typedef unsigned char uch;
using namespace std;

// CLASS POINT
class Point     //coordinates X,Y
{
public:
    void SetPoint(uch x, uch y) {X = x; Y = y;}
    void SetX(uch x) {X = x;}
	void SetY(uch y) {Y = y;}
	uch GetX()const {return X;}
	uch GetY()const {return Y;}
private:
	uch X;
	uch Y;
};

// CLASS LINE
class Line     //points P1, P2
{
public:
    void SetLine(Point p1, Point p2) {P1 = p1; P2 = p2;}//
    Point GetP1()const {return P1;}
    Point GetP2()const {return P2;}
private:
	Point P1;
	Point P2;
};

// CLASS TRIANGLE
class Triangle     //points P1, P2, P3
{
public:
    void SetTriangle(Point p1, Point p2, Point p3);
    Line GetL12()const {return L12;}
    Line GetL23()const {return L23;}
    Line GetL31()const {return L31;}
private:
	Point P1;
	Point P2;
	Point P3;
	Line  L12;
	Line  L23;
	Line  L31;
};

void Triangle::SetTriangle(Point p1, Point p2, Point p3)
{
    P1 = p1;
    P2 = p2;
    P3 = p3;
    L12.SetLine(P1, P2);
    L23.SetLine(P2, P3);
    L31.SetLine(P3, P1);
}

//CLASS RECTANGLE
class Rectangle
{
public:
    void SetRectangle(Point p1, Point p2, Point p3, Point p4);
    Line GetL12()const {return L12;}
    Line GetL23()const {return L23;}
    Line GetL34()const {return L34;}
    Line GetL41()const {return L41;}
private:
	Point P1;
	Point P2;
	Point P3;
	Point P4;
	Line  L12;
	Line  L23;
	Line  L34;
	Line  L41;
};

void Rectangle::SetRectangle(Point p1, Point p2, Point p3, Point p4)
{
    P1 = p1;
    P2 = p2;
    P3 = p3;
    P4 = p4;
    L12.SetLine(P1, P2);
    L23.SetLine(P2, P3);
    L34.SetLine(P3, P4);
    L41.SetLine(P4, P1);
}

// CLASS CANVAS
class Canvas    //uch Height, uch Width, array of character as a pixels of canvas
{
public:
    int SetCanvas(uch width, uch high);       //set size of canvas
    uch GetWidth() const {return W;}          //return width of canvas
    uch GetHeight() const {return H;}         //return height of canvas
    void ClearCanvas(void);                   //clear canvas - all charactes are spaces
    void PrintCanvas(void);                   //display canvas on the screen
    void AddFrame(char pattern);              //add frame in the edges of canvas
    int AddPoint(Point point, char pattern);  //add point
    int AddLine(Line line, char pattern);     //add line from the first point to second point
    int AddTriangle(Triangle tri, char pattern); //add triangle
    int AddRectangle(Rectangle rec, char pattern); //add rectangle

private:
	uch H;
	uch W;
	char Canv[200][200];

};

int Canvas::SetCanvas(unsigned char width, unsigned char height)
{
    if(width <= 200)
        W = width;
    else
    {
        W = 0;
        H = 0;
        return 1;
    }

    if(height <= 200)
        H = height;
    else
    {
        W = 0;
        H = 0;
        return 1;
    }
    return 0;
}

void Canvas::ClearCanvas(void)
{
    int w,h;

    for(h = 0; h < H; h++)
        for(w = 0; w < W; w++)
            Canv[w][h] = ' ';
}

void Canvas::AddFrame(char pattern)
{
    int i;

    for(i = 0; i < W; i++)
    {
        Canv[i][0] = pattern;
        Canv[i][H-1] = pattern;
    }

    for(i = 0; i < H; i++)
    {
        Canv[0][i] = pattern;
        Canv[W-1][i] = pattern;
    }
}

int Canvas::AddPoint(Point point, char pattern)
{
    if((point.GetX() > W) || (point.GetY() > H))
        return 1;
    else
    {
        Canv[point.GetX()][point.GetY()] = pattern;
        return 0;
    }
}


int Canvas::AddLine(Line line, char pattern)
{
    Point Aux1, Aux2;
    int dx, dy;
    uch n, xy;
    float d;

    Aux1 = line.GetP1();
    Aux2 = line.GetP2();

    if(Aux1.GetX() > W || Aux2.GetX() > W || Aux1.GetY() > H || Aux2.GetY() > H)
        return 1;
    else
    {
        dx = Aux2.GetX() - Aux1.GetX();
        dy = Aux2.GetY() - Aux1.GetY();
        if((dx != 0) && (dy != 0))
        {
            if(abs(dx) > abs(dy))
            {
                d = float(dy) / float(dx);
                if(dx > 0)
                {
                    for(n = Aux1.GetX(); n <= Aux2.GetX(); n++)
                    {
                        xy = round(Aux1.GetY() + (n-Aux1.GetX()) * d);
                        Canv[n][xy] = pattern;
                    }
                }
                else
                {
                    for(n = Aux2.GetX(); n <= Aux1.GetX(); n++)
                    {
                        xy = round(Aux2.GetY() + (n-Aux2.GetX()) * d);
                        Canv[n][xy] = pattern;
                    }
                }
            }
            else
            {
                d = float(dx) / float(dy);
                if(dy > 0)
                {
                    for(n = Aux1.GetY(); n <= Aux2.GetY(); n++)
                    {
                        xy = round(Aux1.GetX() + (n-Aux1.GetY()) * d);
                        Canv[xy][n] = pattern;
                    }
                }
                else
                {
                    for(n = Aux2.GetY(); n <= Aux1.GetY(); n++)
                    {
                        xy = round(Aux2.GetX() + (n-Aux2.GetY()) * d);
                        Canv[xy][n] = pattern;
                    }
                }
            }
        }
        else if((dx == 0) && (dy == 0))
        {
            Canv[Aux1.GetX()][Aux1.GetY()] = pattern;
        }
        else if(dx == 0)
        {
            if(dy > 0)
                for(n = Aux1.GetY(); n <= Aux2.GetY(); n++)
                    Canv[Aux1.GetX()][n] = pattern;
            else
                for(n = Aux2.GetY(); n <= Aux1.GetY(); n++)
                    Canv[Aux1.GetX()][n] = pattern;
        }
        else
        {
            if(dx > 0)
                for(n = Aux1.GetX(); n <= Aux2.GetX(); n++)
                    Canv[n][Aux1.GetY()] = pattern;
            else
                for(n = Aux2.GetX(); n <= Aux1.GetX(); n++)
                    Canv[n][Aux1.GetY()] = pattern;
        }
        return 0;
    }
}

int Canvas::AddTriangle(Triangle tri, char pattern)
{
    int out;

    out = AddLine(tri.GetL12(), pattern);
    if(out)
        return 1;
    out = AddLine(tri.GetL23(), pattern);
    if(out)
        return 1;
    out = AddLine(tri.GetL31(), pattern);
    if(out)
        return 1;
    return 0;
}

int Canvas::AddRectangle(Rectangle rec, char pattern)
{
    int out;

    out = AddLine(rec.GetL12(), pattern);
    if(out)
        return 1;
    out = AddLine(rec.GetL23(), pattern);
    if(out)
        return 1;
    out = AddLine(rec.GetL34(), pattern);
    if(out)
        return 1;
    out = AddLine(rec.GetL41(), pattern);
    if(out)
        return 1;
    return 0;
}

void Canvas::PrintCanvas(void)
{
    int w,h;

    for(h = H-1; h >= 0; h--)
    {
         cout << endl;
         for(w = 0; w < W; w++)
            cout << Canv[w][h];
    }
    cout << endl;
}

int main()
{
    Canvas A;
    A.SetCanvas(160, 80);
    /*A.ClearCanvas();
    A.AddFrame(BLOCK);
    A.PrintCanvas();*/

    Point P1;
    /*P1.SetPoint(80,50);
    A.AddPoint(P1, STAR);
    P1.SetPoint(80,60);
    A.AddPoint(P1, CIRCLET);
    P1.SetPoint(80,70);
    A.AddPoint(P1, BLOCK);
    A.PrintCanvas();*/

    Point P2;
    /*P1.SetPoint(10,10);
    P2.SetPoint(150,50);
    Line L1;
    L1.SetLine(P1, P2);
    A.AddLine(L1, CIRCLET);
    P1.SetPoint(10,50);
    P2.SetPoint(150,10);
    L1.SetLine(P1, P2);
    A.AddLine(L1, CIRCLET);
    A.PrintCanvas();*/

    Point P3;
    /*P1.SetPoint(20,30);
    P2.SetPoint(140,30);
    P3.SetPoint(80,75);
    Triangle T;
    T.SetTriangle(P1, P2, P3);
    A.AddTriangle(T, PLUS);
    A.PrintCanvas();*/

    A.ClearCanvas();
    A.AddFrame(BLOCK);

    Point P4;
    P1.SetPoint(10, 5);
    P2.SetPoint(150, 5);
    P3.SetPoint(80,30);
    Triangle T1;
    T1.SetTriangle(P1, P2, P3);
    A.AddTriangle(T1, BLOCK);
    P1.SetPoint(10,75);
    P2.SetPoint(150,75);
    P3.SetPoint(80,50);
    Triangle T2;
    T2.SetTriangle(P1,P2,P3);
    A.AddTriangle(T2, BLOCK);
    P1.SetPoint(10,10);
    P2.SetPoint(10,15);
    P3.SetPoint(150,70);
    P4.SetPoint(150,65);
    Rectangle R1;
    R1.SetRectangle(P1,P2,P3,P4);
    A.AddRectangle(R1, STAR);
    P1.SetPoint(10,65);
    P2.SetPoint(10,70);
    P3.SetPoint(150,15);
    P4.SetPoint(150,10);
    Rectangle R2;
    R2.SetRectangle(P1,P2,P3,P4);
    A.AddRectangle(R2, STAR);

    A.PrintCanvas();

    return 0;
}
