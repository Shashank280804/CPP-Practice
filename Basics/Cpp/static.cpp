#include <graphics.h>
#pragma GCC diagnostic ignored "-Wwrite-strings" // ignores the warning
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
class DDALINE
{
public:
    float x, y, xi, yi, steps, dx, dy;

    void NLINE(int x1, int y1, int x2, int y2);
    void DOLINE(int x1, int y1, int x2, int y2);
    void DALINE(int x1, int y1, int x2, int y2);
    void THLINE(int x1, int y1, int x2, int y2, int w);
};
void DDALINE ::NLINE(int x1, int y1, int x2, int y2)
{
    int i;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }
    x = x1;
    y = y1;
    xi = dx / steps;
    yi = dy / steps;
    putpixel(x, y, WHITE); // here put one
    for (i = 1; i <= steps; i++)
    {
        x = x + xi; // here put till
        y = y + yi;
        putpixel(x, y, WHITE);
    }
};
void DDALINE ::DOLINE(int x1, int y1, int x2, int y2)
{
    int i;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }
    xi = dx / steps;
    yi = dy / steps;
    x = x1;
    y = y1;

    putpixel(x, y, WHITE); // here put one
    for (i = 1; i <= steps; i = i + 4)
    {
        x = x + 4 * xi; // here put till
        y = y + 4 * yi;
        putpixel(x, y, WHITE);
    }
};
void DDALINE ::DALINE(int x1, int y1, int x2, int y2)
{
    int i;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }
    xi = dx / steps;
    yi = dy / steps;
    x = x1;
    y = y1;

    for (i = 1; i <= steps; i++)
    {
        x = x + xi; // here put till
        y = y + yi;
        if (i % 9 > 4)
        {
            putpixel(x, y, WHITE);
        }
    }
};
void DDALINE ::THLINE(int x1, int y1, int x2, int y2, int w)
{
    int i, wy, wx, m;
    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;
    if (m < 1)
    {
        wy = ((w - 1) * sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) / (2 * (x2 - x1));
        for (i = 0; i < wy; i++)
        {
            NLINE(x1, y1 - i, x2, y2 - i);
            NLINE(x1, y1 + i, x2, y2 + i);
        }
    }
    else
    {
        wx = ((w - 1) * sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) / (2 * (y2 - y1));
        for (i = 0; i < wx; i++)
        {
            NLINE(x1 - i, y1, x2 - i, y2);
            NLINE(x1 + i, y1, x2 + i, y2);
        }
    }
}
int main()
{
    DDALINE D;
    int ch;
    int x1, y1, x2, y2, w;
    do
    {
        cout << "\nLine options are.....\n1.Normal\n2.Dotted\n3.Dashed\n4.Thick\n5.Exit\n\nEnter choice
            : ";
              cin >>
            ch;
        if (ch == 1 || ch == 2 || ch == 3 && ch != 5)
        {
            cout << "Enter coordinates of line :\n";
            cin >> x1 >> y1 >> x2 >> y2;
        }
        else if (ch == 4)
        {
            cout << "Enter coordinates of line :\n";
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "Enter width of line :";
            cin >> w;
        }
        int gd = DETECT, gm;
        initgraph(&gd, &gm, (char)*"");

        switch (ch)
        {
        case 1:
            system("cls"); // clear the screen
            setcolor(GREEN);
            D.NLINE(x1, y1, x2, y2);
            outtext("Press any key to continue.......");
            break;
        case 2:
            system("cls");
            setcolor(GREEN);
            D.DOLINE(x1, y1, x2, y2);
            outtext("Press any key to continue.......");
            break;
        case 3:
            system("cls");
            setcolor(GREEN);
            D.DALINE(x1, y1, x2, y2);
            outtext("Press any key to continue.......");
            break;
        case 4:
            system("cls");
            setcolor(GREEN);
            D.THLINE(x1, y1, x2, y2, w);
            outtext("Press any key to continue.......");
            break;
        case 5:
            exit(0);
        default:
            cout << "Enter correct choice!!\n\n";
        }
        getch();
        closegraph();
    } while (ch != 5);
}