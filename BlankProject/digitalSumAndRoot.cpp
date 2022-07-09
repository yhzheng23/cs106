/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include <cmath>
#include "console.h"
#include "simpio.h"
using namespace std;

int digitalSum(int x);
int digitalRoot(int x);

int main()
{
    int n = getInteger("Enter the first number : ");
    cout << "the digital sum is " << digitalRoot(n) << endl;


    return 0;
}


int digitalSum(int x){
    if(x<10) return x;
    return digitalSum(x/10) + (x%10);
}

int digitalRoot(int x){
    if(x<10) return x;
    return digitalRoot(digitalSum(x));
}
