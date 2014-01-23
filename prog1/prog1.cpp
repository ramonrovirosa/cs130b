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

int* quickSortY(int arr[], int arrY[], int left, int right);
int* quickSortX(int arr[], int left, int right);
struct Point;
struct distanceBetweenPoints;
distanceBetweenPoints ClosestPairBruteForce(int totalNumber, int xCords[], int yCords[] );
distanceBetweenPoints ClosestPairDivideConquer(int totalNumber, Point P[], int xCords[], int yCords[] );

struct Point
{
    int x;
    int y;
};

struct distanceBetweenPoints
{
    int x1,y1;
    int x2,y2;
    int distance, comparisons;

};

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

        //BRUTE FORCE ALGORITHM
        distanceBetweenPoints bruteForce = ClosestPairBruteForce(totalNumber,xCords,yCords);
        cout<<bruteForce.x1<<" "<<bruteForce.y1<<" , "<<bruteForce.x2<<" "<<bruteForce.y2<<"\n";
        cout<<bruteForce.comparisons<<"\n";

        //DIVIDE & CONQUER ALGORITHM
        //first sort the arrays by the xCords positions
        int *yCords2 = quickSortY(xCords, yCords, 0,totalNumber-1);
        int *xCords2 = quickSortX(xCords, 0,totalNumber-1);


        Point points[totalNumber];
        for(int i=0;i<totalNumber;i++){
            points[i].x=xCords2[i];
            points[i].y=yCords2[i];
        }
//         for(int i=0;i<totalNumber;i++){
//                    cout<<"X position" <<i<< ": "<<points[i].x<<" , ";
//                    cout<<"Y position: "<<points[i].y<<"\n";
//         }
        ClosestPairDivideConquer(totalNumber,points,xCords2,yCords2);
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

distanceBetweenPoints ClosestPairBruteForce(int totalNumber, int xCords[], int yCords[] ){
    int distanceMinimum=-1;
    int iMinimum[2];
    int jMinimum[2];
    int comparisons=0;

    for(int i=0;i<totalNumber;i++){
       for(int j=i+1;j<totalNumber;j++){
        int p[2]= {xCords[i],yCords[i]};
        int q[2]= {xCords[j],yCords[j]};
        //distance formula (x2-x1)^2 + (y2-y1)^2
        int distance = pow(q[0]-p[0],2)+ pow(q[1]-p[1],2);
        if(distanceMinimum == -1){ distanceMinimum = distance;
        iMinimum[0] = xCords[i];
        iMinimum[1] = yCords[i];

        jMinimum[0] = xCords[j];
        jMinimum[1] = yCords[j];
        }
        else if(distanceMinimum > distance) {
            distanceMinimum = distance;
            iMinimum[0] = xCords[i];
            iMinimum[1] = yCords[i];

            jMinimum[0] = xCords[j];
            jMinimum[1] = yCords[j];
        }
        comparisons++;
       }
    }

    distanceBetweenPoints min = {iMinimum[0], iMinimum[1],jMinimum[0],jMinimum[1],distanceMinimum, comparisons};
    return min;
}

//Divide & Conquer
//Brute Force
distanceBetweenPoints ClosestPairDivideConquer(int totalNumber, Point point[], int xCords[], int yCords[] ){
    // If there are 2 or 3 points, then use brute force
    if (totalNumber <= 3)
        return ClosestPairBruteForce(totalNumber, xCords,yCords);
    else{
        //midpoint
        int middle = (totalNumber-1)/2;
        Point midPoint = point[middle];

        int leftX[middle];
        int leftY[middle];
        int rightX[totalNumber-middle];
        int rightY[totalNumber-middle];
        for(int i=0;i<totalNumber;i++){
            if(i<=middle){
                leftX[i]=xCords[i];
                leftY[i]=yCords[i];
            }else{
                rightX[i] = xCords[i];
                rightY[i] = xCords[i];
            }
        }

        // Consider the vertical line passing through the middle point
        // calculate the smallest distance dl on left of middle point and
        // dr on right side
        distanceBetweenPoints dl = ClosestPairDivideConquer(middle, point, leftX, leftY );
        distanceBetweenPoints dr = ClosestPairDivideConquer(totalNumber-middle, point + middle, rightX, rightY);

        distanceBetweenPoints d = (dl.distance < dr.distance)? dl : dr;

        return d;



    }



}

//sort the y array
int* quickSortY(int arr[], int arrY[], int left, int right)
 {
  int i = left, j = right;
  int tmp,tmpY;
  int pivot = arr[(left + right) / 2];

  /* partition */
  while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];
              tmpY=arrY[i];

              arr[i] = arr[j];
              arrY[i]= arrY[j];

              arr[j] = tmp;
              arrY[j]=tmpY;

              i++;
              j--;
    }
}
/* recursion */
if (left < j)
    quickSortY(arr, arrY, left, j);
if (i < right)
    quickSortY(arr, arrY, i, right);

return arrY;
}
//sort the x array
int* quickSortX(int arr[], int left, int right)
 {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  /* partition */
  while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];

              arr[i] = arr[j];

              arr[j] = tmp;

              i++;
              j--;
    }
}
/* recursion */
if (left < j)
    quickSortX(arr, left, j);
if (i < right)
    quickSortX(arr, i, right);

return arr;
}