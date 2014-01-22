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
#include <math.h>
#include "generateData.cpp"

using namespace std;

void ClosestPairBruteForce(int totalNumber, int xCords[], int yCords[] );
void ClosestPairDivideConquer(int totalNumber, int xCords[], int yCords[] );

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
//            cout<<"X position" <<i<< ": "<<xCords[i]<<"\n";
//            cout<<"Y position: "<<yCords[i]<<"\n";
//        }

        myfile.close();
        ClosestPairBruteForce(totalNumber,xCords,yCords);
    }
    else cout << "Unable to open file";

    return 0;
}

//Brute Force
//minDist = infinity
//for i = 1 to length(P) - 1
// for j = i + 1 to length(P)
//  let p = P[i], q = P[j]
//  if dist(p, q) < minDist:
//   minDist = dist(p, q)
//   closestPair = (p, q)
//return closestPair

void ClosestPairBruteForce(int totalNumber, int xCords[], int yCords[] ){
    int distanceMinimum=-1;
    int iMinimum[2],jMinimum[2];

    for(int i=0;i<totalNumber-1;i++){
       for(int j=i+1;j<totalNumber;j++){
        int p[2]= {xCords[i],yCords[i]};
        int q[2]= {xCords[j],yCords[j]};
        //distance formula (x2-x1)^2 + (y2-y1)^2
        int distance = pow(q[0]-p[0],2)+ pow(q[1]-p[1],2);
        if(distanceMinimum == -1) distanceMinimum = distance;
        else if(distanceMinimum > distance) {
            distanceMinimum = distance;
            iMinimum[0] = xCords[i]; iMinimum[1] = yCords[i];
            jMinimum[0] = xCords[j]; jMinimum[1] = yCords[j];
        }
       }
    }
    cout<<"distanceMinimum: "<< distanceMinimum << "\n";
    cout<<"point1: "<< iMinimum[0]<<","<<iMinimum[1] << "\n";
    cout<<"point2: "<< jMinimum[0]<<","<<jMinimum[1] << "\n";

}

//Divide & Conquer
//Brute Force
void ClosestPairDivideConquer(int totalNumber, int xCords[], int yCords[] ){
    //Divide & Conquer
}