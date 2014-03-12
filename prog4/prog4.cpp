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

 struct Error{
    pointsXY point;
    double error;
 };

bool compareSmallest (Error a, Error b) { return (a.error < b.error); }


 int main(){
    //get x,y points form input
    int n=0;
    char name[256];
    string x,y, comb;
    pointsXY input;
    vector<string> tokens;
    vector<pointsXY> points, optimalPoints;
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
//    while(iter<n){
    while(iter<5){
        int seed1=rand()%n;
        int seed2=rand()%n;
        while(seed1==seed2){
            seed2=rand()%n;
        }
        iter++;
        pointsXY p1 = points[seed1];
        pointsXY p2 = points[seed2];

        //y=mx+b
        double m = (p2.y-p1.y)/(p2.x-p1.x);
        double b = p1.y-(m*p1.x);


        //find the distance to the currently selected line
        vector<Error>distance;
        for(int i = 0;i < n; i++){
            if(!(i == seed1 || i == seed2)) {
                double err = points[i].y - (b + m*points[i].x);
                err = max(err, -err);
                Error a;
                a.point=points[i];
                a.error=err;
                distance.push_back(a);
            }
        }
        sort(distance.begin(), distance.end(), compareSmallest);
        int mid=distance.size()/2;
        if(distance[mid].error<bestMedianEror || bestMedianEror<0){
            bestMedianEror=distance[mid].error;
            optimalPoints.clear();
            for(int j=0;j<mid;j++){
                optimalPoints.push_back(distance[j].point);
//                cout<<optimalPoints[j].x<<endl;
            }
        }
    }

    double x_times_y = 0;
    double _x = 0;
    double _y = 0;
    double x_squared = 0;
    int size=optimalPoints.size();

    for(int i = 0; i <size; i++){
           _x += optimalPoints[i].x;
           _y += optimalPoints[i].y;
          x_times_y += optimalPoints[i].x*optimalPoints[i].y;
          x_squared += optimalPoints[i].x*optimalPoints[i].x;
     }
    double denom = size*x_squared - x_squared;
    double m = (size*x_times_y - _x*_y)/denom;
    double b = (_y*x_squared - _x*x_times_y)/denom;

    cout << m << " " << b << endl;

    return 0;
 }
