/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include <cmath>
#include "console.h"
#include "simpio.h"
using namespace std;

#include "gwindow.h"

int main()
{
    //int n = getInteger("Enter the number of darts : ");
    //cout << "there are " << n << " darts." << endl;

    //draw canvas
    GWindow gw;
    gw.setBackground("CYAN");
    //draw circles: red, orange, yellow, green, blue, and magenta
    double w = gw.getWidth();
    double h = gw.getHeight();

    /*assume the most inner "CYAN" circle is 1/4 of the whole length, i.e. 45 degree.
      then use triangle equation to calculate rmin, xoffset, yoffset for the most inner circle
      calculate other circles by adding band
    */
    double band =20;
    double rmin = w/sqrt(2);
    double xoffset = -(rmin-w/2);
    double yoffset = (1-1/sqrt(2))*rmin;

    gw.setColor("RED");
    gw.fillOval(xoffset-band*6,h-(yoffset+band*6),(rmin+band*6)*2,(rmin+band*6)*2);
    gw.setColor("ORANGE");
    gw.fillOval(xoffset-band*5,h-(yoffset+band*5),(rmin+band*5)*2,(rmin+band*5)*2);
    gw.setColor("YELLOW");
    gw.fillOval(xoffset-band*4,h-(yoffset+band*4),(rmin+band*4)*2,(rmin+band*4)*2);
    gw.setColor("GREEN");
    gw.fillOval(xoffset-band*3,h-(yoffset+band*3),(rmin+band*3)*2,(rmin+band*3)*2);
    gw.setColor("BLUE");
    gw.fillOval(xoffset-band*2,h-(yoffset+band*2),(rmin+band*2)*2,(rmin+band*2)*2);
    gw.setColor("MAGENTA");
    gw.fillOval(xoffset-band*1,h-(yoffset+band),(rmin+band)*2,(rmin+band)*2);
    gw.setColor("CYAN");
    gw.fillOval(xoffset,h-yoffset,rmin*2,rmin*2);

    return 0;
}

