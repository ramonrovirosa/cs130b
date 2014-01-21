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
    int totalNumber = atoi(line.c_str());
    int xCords[totalNumber];
    int yCords[totalNumber];

    char c;
    string num1 = "";
    string num2 = "";

    while ( (c = myfile.get()) != ' ' ){
        num1 += c;
    }
    while ( (c = myfile.get()) != '\n' ){
        num2 += c;
    }

//        while ( getline (myfile,line) )
//        {

//          getline(myfile,line);
          cout << "num1: "<<num1<<'\n';
          cout << "num2: "<<num2<<'\n';
//        }
//        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}
