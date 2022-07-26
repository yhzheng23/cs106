/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "filelib.h"
using namespace std;
#include <iomanip>
#include <iostream>

void removeComments(istream& is, ostream& os);

int main()
{
    //int n = getInteger("Enter n for c(n,k) (n>=k): ");
    //int k = getInteger("Enter k for c(n,k) (n>=k): ");
    //string str =  getLine("Enter file name: ");
    //cout << "root : " << myGetRoot(str) << endl;
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    removeComments(infile, cout);

    return 0;
}

void removeComments(istream& is, ostream& os){
    char curCh;
    char nextCh;
    bool isLineComment=false;
    bool isBlockComment=false;

    //empty in-stream
    if(!is.get(curCh))
        return;

    while(is.get(nextCh)){

        if(isBlockComment){
            if(curCh=='*' && nextCh=='/'){
                isBlockComment=false;
                is.get(curCh); //finish comment, get one-step further
            }
            else{
                curCh=nextCh;
            }
            continue;
        }

        if(isLineComment){
            if(nextCh=='\n'){
                isLineComment=false;
                os.put(nextCh);
                is.get(curCh);
            }
            continue;
        }

        if(curCh=='/' && nextCh=='*'){
            isBlockComment=true;
            curCh=nextCh;
            continue;
        }

        if(curCh=='/' && nextCh=='/'){
            isLineComment=true;
            continue;
        }

        os.put(curCh);
        curCh=nextCh;
    }
    if( (!isBlockComment) && (!isLineComment) )
        os.put(curCh);
}
