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
    if (myfile.is_open()){
        getline(myfile,line);
        int totalNumber = atoi(line.c_str());
        int xCords[totalNumber];
        int yCords[totalNumber];

        char c;
        string numX = "";
        string numY = "";
        int index=0;

        while ( true ){

            //put x value into array
            while ( (c = myfile.get()) != ' ' ){
                if(c == EOF)
                    goto arraysCreated;
                numX += c;
            }
            xCords[index]=atoi(numX.c_str());
            //put y value into array
            while ( (c = myfile.get()) != '\n' ){
                if(c == EOF)
                    goto arraysCreated;
                numY += c;
            }
            yCords[index]=atoi(numY.c_str());
            index++;
            numX="";
            numY="";
        }
        arraysCreated:
//        for(int i=0;i<totalNumber;i++){
//            cout<<"X position:" <<xCords[i]<<"\n";
//            cout<<"Y position: "<<yCords[i]<<"\n";
//        }

        myfile.close();
    }
    else cout << "Unable to open file";

    return 0;
}
