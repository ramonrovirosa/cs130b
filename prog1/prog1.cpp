/*
 * File:   main.cpp
 * Author: nguyenvandonganh
 *
 * Created on January 13, 2014, 4:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "generateData.cpp"

using namespace std;

int main() {
    generatePoints();

    string line;
    ifstream myfile ("points300.txt");
    if (myfile.is_open())
    {
//        while ( getline (myfile,line) )
//        {
          cout << line << '\n';
//        }
//        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}
