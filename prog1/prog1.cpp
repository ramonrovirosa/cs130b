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
    getline(myfile,line);
//    cout << "The number of values is" <<line << '\n';
    int totalNumber = atoi(line.c_str());
    int xCords[totalNumber];
    int yCords[totalNumber];

//        while ( getline (myfile,line) )
//        {

          getline(myfile,line);
          cout << "points: "<<line<<'\n';
//        }
//        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}
