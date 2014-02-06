/*
    Ramon Rovirosa
    CS130B
    Prog2
    MCST
 */

 #include <cstdlib>
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <vector>
 #include <math.h>
 #include <stdio.h>
 #include <limits.h>

 using namespace std;

 struct Point
 {
     float x;
     float y;
     Point(float x1, float y1):x(x1),y(y1){}
 };

 int main(){
    string line;
    getline(cin,line);
    int totalNumber = atoi(line.c_str());

    vector<Point> points;

    char c;
    string numX = "";
    string numY = "";

    while ( true ){
        while ( (c = cin.get()) != ' ' ){
            if(c == EOF)
                goto arraysCreated;
            numX += c;
        }
        while ( (c = cin.get()) != '\n' ){
            if(c == EOF)
                goto arraysCreated;
            numY += c;
        }
        points.push_back(Point(atof(numX.c_str()),atof(numY.c_str())));
        numX="";
        numY="";
    }
    arraysCreated:
    //we now have all our points in a vector array points



    return 0;
 }