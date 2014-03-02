/*
    Ramon Rovirosa
    CS130B
    Prog3
 */

 #include <cstdlib>
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <vector>
 #include <math.h>
 #include <stdio.h>
 #include <float.h>

 using namespace std;

//min(a,b, leftMatrix, topMatrix, diagonalMatrix, x, y, match, change, del)
 double min(int a, int b,
            double leftMatrix, double topMatrix, double diagonalMatrix,
            double match, double change, double del){

    return 5.0;
 }



 int main(int argc, char* argv[]){
    string x="GACGGATTAG";
    string y="GATCGGAATAG";

    int i = x.length();
    int j = y.length();

    double match=2.0;
    double change=-.5;
    double del=-1.0;

    double Matrix[i][j];

    for(int a=0;a<i;a++){
        Matrix[a][0] = 1.0;
    }
    for(int b=0;b<j;b++){
        Matrix[0][b] = 1.0;
    }
    cout<<"Matrix[0][10] "<<Matrix[0][10]<<endl;
    Matrix[0][0]=(x[0]==y[0])?2.0:-0.5;

   for (int a = 1; a < j; a++){
       for(int b=1; b<i;b++){
            double leftMatrix=Matrix[a-1][b];
            double topMatrix=Matrix[a][b-1];
            double diagonalMatrix=Matrix[a-1][b-1];
            Matrix[b][a] = min(a,b, leftMatrix, topMatrix, diagonalMatrix, match, change, del);
        }
    }

    for (int a=0; a< j;a++){
            for(int b=0; b<i;b++){
                cout<<Matrix[b][a]<< " ";
            }
            cout<<endl;
        }

    return 0;
 }