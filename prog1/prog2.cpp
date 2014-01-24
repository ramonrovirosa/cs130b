/*
    Ramon Rovirosa
    CS130B
    Prog1
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "generateData.cpp"

using namespace std;

float* quickSortY(float arr[], float arrY[], int left, int right);
float* quickSortX(float arr[], int left, int right);
struct Point;
struct distanceBetweenPoints;
int compareY(const void* a, const void* b);
int compareX(const void* a, const void* b);
distanceBetweenPoints ClosestPairBruteForce(int totalNumber, float xCords[], float yCords[] );
distanceBetweenPoints ClosestPairDivideConquer(int totalNumber, Point P[], float xCords[], float yCords[] );

struct Point
{
    float x;
    float y;
};

struct distanceBetweenPoints
{
    float x1,y1;
    float x2,y2;
    float distance;
    int comparisons;

};

int main() {
//    generatePoints();

    string line;
//    ifstream myfile ("points300.txt");
//    if (myfile.is_open()){
        getline(cin,line);
        int totalNumber = atoi(line.c_str());
//        cout<<"total number: "<<totalNumber<<"\n";
        float xCords[totalNumber];
        float yCords[totalNumber];

        char c;
        string numX = "";
        string numY = "";
        int index=0;

        while ( true ){

            //put x value into array
            while ( (c = cin.get()) != ' ' ){
                if(c == EOF)
                    goto arraysCreated;
                numX += c;
            }
            xCords[index]=atof(numX.c_str());
            //put y value into array
            while ( (c = cin.get()) != '\n' ){
                if(c == EOF)
                    goto arraysCreated;
                numY += c;
            }
            yCords[index]=atof(numY.c_str());
            index++;
            numX="";
            numY="";
        }
        arraysCreated:
//        for(int i=0;i<totalNumber;i++){
//            cout<<"X position" <<i<< ": "<<xCords[i]<<"\n";
//            cout<<"Y position: "<<yCords[i]<<"\n";
//        }

//        myfile.close();

        //BRUTE FORCE ALGORITHM
        distanceBetweenPoints bruteForce = ClosestPairBruteForce(totalNumber,xCords,yCords);
        cout<<bruteForce.x1<<" "<<bruteForce.y1<<" "<<bruteForce.x2<<" "<<bruteForce.y2<<"\n";
        cout<<bruteForce.comparisons<<"\n";

        //DIVIDE & CONQUER ALGORITHM
        //first sort the arrays by the xCords positions
//        float *yCords2 = quickSortY(xCords, yCords, 0,totalNumber-1);
//        float *xCords2 = quickSortX(xCords, 0,totalNumber-1);

        Point divConqPre[totalNumber];
        for(int i=0;i<totalNumber;i++){
               divConqPre[i].x=xCords[i];
               divConqPre[i].y=yCords[i];
        }
        qsort(divConqPre, totalNumber, sizeof(Point), compareX);
        float xCords2[totalNumber];
        float yCords2[totalNumber];
        for(int i=0;i<totalNumber;i++){
           xCords2[i] = divConqPre[i].x;
           yCords2[i]=  divConqPre[i].y;
        }

        Point points[totalNumber];
        for(int i=0;i<totalNumber;i++){
            points[i].x=xCords2[i];
            points[i].y=yCords2[i];
        }

        distanceBetweenPoints DivideAndConquer = ClosestPairDivideConquer(totalNumber,points,xCords2,yCords2);
        cout<<DivideAndConquer.x1<<" "<<DivideAndConquer.y1<<" "<<DivideAndConquer.x2<<" "<<DivideAndConquer.y2<<"\n";
        cout<<DivideAndConquer.comparisons<<"\n";
//    }
//    else cout << "Unable to open file";

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

distanceBetweenPoints ClosestPairBruteForce(int totalNumber, float xCords[], float yCords[] ){
    float distanceMinimum=-1;
    float iMinimum[2];
    float jMinimum[2];
    int comparisons=0;

    for(int i=0;i<totalNumber;i++){
       for(int j=i+1;j<totalNumber;j++){
        float p[2]= {xCords[i],yCords[i]};
        float q[2]= {xCords[j],yCords[j]};
        //distance formula (x2-x1)^2 + (y2-y1)^2
        float distance = pow(q[0]-p[0],2)+ pow(q[1]-p[1],2);
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

    distanceBetweenPoints d = {iMinimum[0], iMinimum[1],jMinimum[0],jMinimum[1],distanceMinimum, comparisons};
     if(d.x1 > d.x2 || (d.x1==d.x2 && d.y1 > d.y2)){
                float xtemp, ytemp;
                xtemp=d.x1;
                ytemp=d.y1;
                d.x1=d.x2;
                d.y1=d.y2;
                d.x2=xtemp;
                d.y2=ytemp;
     }
    return d;
}

//Divide & Conquer
//Brute Force
distanceBetweenPoints ClosestPairDivideConquer(int totalNumber, Point point[], float xCords[], float yCords[] ){
    // If there are 2 or 3 points, then use brute force
    if (totalNumber <= 3){
        return ClosestPairBruteForce(totalNumber, xCords,yCords);
    }
    else{
        //midpoint
        int middle = (totalNumber)/2;
        Point midPoint = (totalNumber%2)?point[middle]:point[middle-1];

        float leftX[middle];
        float leftY[middle];
        float rightX[totalNumber-middle];
        float rightY[totalNumber-middle];
        Point left[middle];
        Point right[totalNumber-middle];
        for(int i=0;i<totalNumber;i++){
            if(i<middle){
                leftX[i]=xCords[i];
                leftY[i]=yCords[i];
                left[i].x=xCords[i]; left[i].y=yCords[i];
            }else{
                rightX[i-middle] = xCords[i];
                rightY[i-middle] = yCords[i];
                right[i-middle].x=xCords[i]; right[i-middle].y=yCords[i];
            }
        }

        // Consider the vertical line passing through the middle point
        // calculate the smallest distance dl on left of middle point and
        // dr on right side
        distanceBetweenPoints dl = ClosestPairDivideConquer(middle, left, leftX, leftY );
        distanceBetweenPoints dr = ClosestPairDivideConquer(totalNumber-middle, right, rightX, rightY);
        distanceBetweenPoints d = (dl.distance < dr.distance)? dl : dr;
        d.comparisons = dl.comparisons + dr.comparisons;

//        cout<<"x1y1, x2y2: "<<d.x1<<" "<<d.y1<<" , "<<d.x2<<" "<<d.y2<<" distance :"<<d.distance<<"\n";

        // Build an array strip[] that contains points close (closer than d)
        // to the line passing through the middle point
        Point strip[totalNumber];
        int j = 0;
        for (int i = 0; i < totalNumber; i++){
            if (fabs(point[i].x - midPoint.x) < sqrt(d.distance))
                strip[j] = point[i], j++;
         }

        float min = sqrt(d.distance);  // Initialize the minimum distance as d
        qsort(strip, j, sizeof(Point), compareY);

        // Pick all points one by one and try the next points till the difference
        // between y coordinates is smaller than d.
        // This is a proven fact that this loop runs at most 6 times
        for (int i = 0; i < j; ++i){
            for (int k = i+1; k < j && (strip[k].y - strip[i].y) < min; ++k){
                float compare = sqrt(pow((strip[i].x - strip[k].x),2)+pow((strip[i].y - strip[k].y),2));
                if (  compare < min){
                    min = compare;
                    d.x1=strip[i].x; d.y1=strip[i].y;
                    d.x2=strip[k].x; d.y2=strip[k].y;
                    d.comparisons++;
                    d.distance=pow(min,2);
                }
            }
        }
        //arrange the ordered pair from smallest x to largest x
        if(d.x1 > d.x2 || (d.x1==d.x2 && d.y1 > d.y2)){
            float xtemp, ytemp;
            xtemp=d.x1;
            ytemp=d.y1;
            d.x1=d.x2;
            d.y1=d.y2;
            d.x2=xtemp;
            d.y2=ytemp;
        }
        return d;
    }
}

//sort the y array
float* quickSortY(float arr[], float arrY[], int left, int right)
 {
  int i = left, j = right;
  float tmp,tmpY;
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
              arrY[j]= tmpY;

              i++;
              j--;
        }
  }
    /* recursion */
    if (left < j)
        quickSortY(arr, arrY, left, j);
    if (i < right)
        quickSortY(arr, arrY, i, right-1);

    return arrY;
}
//sort the x array
float* quickSortX(float arr[], int left, int right)
 {
  int i = left, j = right;
  float tmp;
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
        quickSortX(arr, i, right-1);

    return arr;
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->x - p2->x);
}