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
 float getDistance(float x1, float y1, float x2, float y2);

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

    //Adjacency matrix array
    float primsGraph[totalNumber][totalNumber];
    float distance;
    for(int i=0; i< points.size();i++){
        for(int j=0; j<points.size();j++){
            distance = getDistance(points.at(j).x,points.at(j).y,
                                   points.at(i).x,points.at(i).y
            );
            primsGraph[i][j]=distance;
        }
    }

   //prims Adjacency matrix complete
   int checkedVertices[totalNumber];
   int edgeMaxWeight[totalNumber];
   bool verticesAdded[totalNumber];

   //initially no vertices are mcst &&
   //no edges are minimum
   for(int i=0;i<totalNumber;i++){
        verticesAdded[i]=false;
        edgeMaxWeight[i]=INT_MAX;
   }

   //choose the first edge & initialize explicit
    edgeMaxWeight[0]=0;
    checkedVertices[0]=-1;

    return 0;
 }

 float getDistance(float x1, float y1, float x2, float y2){
     return sqrt(pow((x1 - x2),2)+pow((y1 - y2),2));
 }