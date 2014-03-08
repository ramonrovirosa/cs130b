/*
    Ramon Rovirosa
    CS130B
    Prog4
 */

 #include <cstdlib>
 #include <iostream>
 #include <vector>
 #include <cmath>
 #include <stdio.h>
 #include <float.h>
 #include <string>
 #include <sstream>
 #include <algorithm>
 #include <iterator>

 using namespace std;

 struct pointsXY {
    double x;
    double y;
 };

 int main(){
    //get x,y points form input
    int n=0;
    char name[256];
    string x,y, comb;
    pointsXY input;
    vector<string> tokens;
    vector<pointsXY> points;
    size_t found;

    while( cin.getline(name, 256)){
        //results in name
        comb = name;
         istringstream iss(comb);
            copy(istream_iterator<string>(iss),
                     istream_iterator<string>(),
                     back_inserter<vector<string> >(tokens));
        n++;
    }
    for(int i=0,j=0;i<n;i++){
        input.x=strtof(tokens[j].c_str(),NULL);
        input.y=strtof(tokens[j+1].c_str(), NULL);
        points.push_back(input);
        j=j+2;
    }

    int bestMedianEror=-1;
    int iter=0;
    int nIter=30;
    while(iter<nIter){
        int seed1=rand()%n;
        int seed2=rand()%n;
        while(seed1==seed2){
            seed2=rand()%n;
        }
        iter++;
        pointsXY p1 = points[seed1];
        pointsXY p2 = points[seed2];

        double m = (p2.y-p1.y)/(p2.x-p1.x);
        double b = p1.y-(m*p1.x);

        //

    }
    return 0;
 }