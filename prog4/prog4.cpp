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

    return 0;
 }