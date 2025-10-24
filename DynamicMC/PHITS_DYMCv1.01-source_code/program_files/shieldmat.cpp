#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(){

    string linedummy;
    int size = 0;

    ifstream infile("shieldmat.tmp");

     while (std::getline(infile, linedummy))
        ++size;
   infile.close();

    ofstream myfilecount;
  myfilecount.open("linecounts.tmp");
  myfilecount << size;
  myfilecount.close();
  
   return 0;

}