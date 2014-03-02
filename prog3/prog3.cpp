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
double max(double left, double top, double diagonal){
    double comp1 = left>top?left:top;
    double max_  = diagonal>comp1? diagonal : comp1;
    return max_;
}


//min(a,b, leftMatrix, topMatrix, diagonalMatrix, x, y, match, change, del)
 double compute(int a, int b,
            double leftMatrix, double topMatrix, double diagonalMatrix,
            string x, string y,
            double match, double change, double del){

    double sim;
    cout<<"x["<<a<<"] "<<x[a]<<" y["<<b<<"] "<<y[b]<<endl;
    if(x[a] == y[b])
        sim=match;
    else
        sim=change;

    double left= leftMatrix + del;
    double top = topMatrix + del;
    double diagonal = diagonalMatrix + sim;

    return max(left,top,diagonal);

 }



 int main(int argc, char* argv[]){
    string x="GACGGATTAG";
    string y="GATCGGAATAG";

    int i = x.length();
    int j = y.length();

//    double match=2.0;
//    double change=-.5;
//    double del=-1.0;

    double match=1;
    double change=-1.0;
    double del=-2.0;

    double Matrix[i][j];

    for(int a=0;a<i;a++){
        Matrix[a][0] = a*del;
    }
    for(int b=0;b<j;b++){
        Matrix[0][b] = b*del;
    }
    Matrix[0][0]=(x[0]==y[0])?match:change;

   //b=x, a=y
   for (int a = 1; a < j; a++){
       for(int b=1; b<i;b++){
            double leftMatrix=Matrix[b-1][a];
            double topMatrix=Matrix[b][a-1];
            double diagonalMatrix=Matrix[b-1][a-1];

            Matrix[b][a] = compute(b,a, leftMatrix, topMatrix, diagonalMatrix,x,y,match, change, del);
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