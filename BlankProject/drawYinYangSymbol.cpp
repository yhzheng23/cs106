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

    double w = gw.getWidth();
    double h = gw.getHeight();

    double xCenter = w/2;
    double yCenter = h/2;
    double r = 150;
    double rSmall = r/5;

    //draw half-white half-black circle
    gw.setColor("BLACK");
    gw.fillOval(xCenter-r,yCenter-r,2*r,2*r);
    gw.setColor("WHITE");
    //move towards top-left by 1 pixal, extend rect size by 1 pixel, to completely cover black circle
    gw.fillRect(xCenter-r-1,yCenter-r-1,r+1,2*r+1);
    gw.setColor("BLACK");
    gw.drawOval(xCenter-r,yCenter-r,2*r,2*r);

    //draw the curve
    gw.setColor("WHITE");
    gw.fillOval(xCenter-r/2,yCenter-r,r,r);
    gw.setColor("BLACK");
    gw.fillOval(xCenter-r/2,yCenter,r,r);

    //draw the circles in middle
    gw.setColor("BLACK");
    gw.fillOval(xCenter-rSmall,yCenter-r/2-rSmall,rSmall*2,rSmall*2);
    gw.setColor("WHITE");
    gw.fillOval(xCenter-rSmall,yCenter+r/2-rSmall,rSmall*2,rSmall*2);

    return 0;
}

