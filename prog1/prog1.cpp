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

//int generatePoints() {
//    ofstream myfile;
//    myfile.open("points300.txt");
//    if (myfile.is_open()) {
//        string input;
//        int totalNumber;
//        int biggestX;
//        int biggestY;
//        cout << "Please enter an integer value: ";
//        getline(cin, input);
//        totalNumber = atoi(input.c_str());
//        myfile << totalNumber << endl;
//        cout << "Largest X value: ";
//        getline(cin, input);
//        biggestX = atoi(input.c_str());
//        cout << "Largest Y value: ";
//        getline(cin, input);
//        biggestY = atoi(input.c_str());
//        for (int i = 0; i < totalNumber; i++) {
//            int xcor = rand() % biggestX + 1;
//            int ycor = rand() % biggestY + 1;
//            stringstream xcorStr;
//            xcorStr << xcor;
//            stringstream ycorStr;
//            ycorStr << ycor;
//            string line = xcorStr.str() + " " + ycorStr.str() + "\n";
//            cout << line;
//            myfile << line;
//        }
//        myfile.close();
//    } else {
//        cout << "Can't open the file!" << endl;
//    }
//
//    return 0;
//}

/*
 *
 */

int main() {
    generatePoints();
    return 0;
}
