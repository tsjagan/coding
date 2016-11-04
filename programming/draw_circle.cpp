#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

double precision = 0.1;

void draw_circle(double radius)
{
    // From (-r,0) to (0,r),
    // x+=precision, y+=precision
    // radius - (x - radius)
    // -(y)
    double i = 0;
    double sx = radius, sy = 0; 
    while ( i <= (radius/precision) ) {
        cout << "First  : (" << -sx << "," << sy << "), ";
        cout << "Second : (" << sx << "," << sy << "), ";
        cout << "Third  : (" << -sx << "," << -sy << "), ";
        cout << "Fourth : (" << sx << "," << -sy << ")";
        sy += precision;
        sx -= precision;
        i++;
        cout << endl;
    }
}

int main(void)
{
    double radius = 0;
    cout << "Enter radius:";
    cin >> radius;
    draw_circle(radius);
    return 0;
}
