#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

double precision = 0.2;
void _draw_quadrant1(double radius, double sx, double sy)
{
    double end = sx + radius;
    while ( sx < end ) {
        cout << sx << " " << sy << " ";
        sy += precision;
        sx += precision;
    }
    cout << endl;
}

void draw_circle(double radius, double cx, double cy)
{
    _draw_quadrant1(radius, cx-radius, cy-radius);
    //_draw_quadrant2(radius, cx+radius, cy+radius);
    //_draw_quadrant3(radius, cx+radius, cy);
    //_draw_quadrant4(radius, cx-radius, cy-radius);
}

int main(void)
{
    double cx = 0, cy = 0, radius = 0;
    cout << "Enter center x :";
    cin >> cx;
    cout << "Enter center x :";
    cin >> cy;
    cout << "Enter radius:";
    cin >> radius;
    draw_circle(radius, cx, cy);
    return 0;
}
