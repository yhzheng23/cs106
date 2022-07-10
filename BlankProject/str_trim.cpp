/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include <cmath>
#include "console.h"
#include "simpio.h"
using namespace std;

string trim(string str);

int main()
{
    //int n = getInteger("Enter n for c(n,k) (n>=k): ");
    //int k = getInteger("Enter k for c(n,k) (n>=k): ");
    string str =  getLine("Enter string: ");
    //string suffix =  getLine("Enter suffix: ");
    cout << str << " trimmed into \"" << trim(str) << "\"" << endl;

    return 0;
}

string trim(string str){
    if(str.length()==0) return "";
    int start=-1;
    int end=str.length();
    for(int i=0; i<str.length(); i++){
        if(!isspace(str[i])){
            start=i;
            break;
        }
    }
    for(int i=str.length()-1; i>=0; i--){
         if(!isspace(str[i])){
             end=i;
             break;
         }
    }
    if(start<0 || end==str.length() || start>end) return "";
    return str.substr(start,end-start+1);
}
