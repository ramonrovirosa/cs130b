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
 #include <string.h>

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
//    cout<<"x["<<a<<"] "<<x[a]<<" y["<<b<<"] "<<y[b]<<endl;
    if(x[a-1] == y[b-1]){
        sim=match;
    }else{
        sim=change;
    }

    double left = leftMatrix + del;
    double top  = topMatrix + del;
    double diagonal = diagonalMatrix + sim;

    return max(left,top,diagonal);

 }



 int main(int argc, char* argv[]){
    string input1 = argv[2];
    string input2 = argv[4];

    string x,y;

     ifstream myReadFile;
     myReadFile.open(input1.c_str());
     char output[5000];
     if (myReadFile.is_open()) {
     while (!myReadFile.eof()) {

        myReadFile >> output;
        x = output;
     }
    }
    myReadFile.close();

    ifstream myReadFile2;
         myReadFile2.open(input2.c_str());
         char output2[5000];
         if (myReadFile2.is_open()) {
         while (!myReadFile2.eof()) {

            myReadFile2 >> output2;
            y = output2;
         }
    }
    myReadFile2.close();

//    x="ATGGCGTTTAACCTTTCTGCAAAGAGCGCTTTCATTGTCGCGCTGCTGGCTTTCAGCGCCAGTGCTACACCTGTCGAACCCATCAGCCCTTGCGCCGCTGTAACCTGCAGCACCAATACCTTTTGCAATGTCATCAACGGCAAACCCGTATGCCTACCCATTTCGAGGCAGCAAAAATGTGGCAAGGCTGTTTGCGCCCCTGGCCACGTTTGCTGCAATTCTTCTTGTGGCATCTGCACCAAGCCCGGCGGCGTGTGCACTCAGCAAATCTGCCCAGATATCGAGTTACAGCCTGTTGAGCCTGCTCCTACGGTCGACAAGAGGGAGGACATTGTGAAGATTGAGGAGCCGGAACTCCCAGCGGTGAAGCCAACGAAGTGCGGACCTACACTTTGTGCTCCTGGAATAGTGTCTAGAGGCCACTTCTTCACCTGCCCCTCGCTACCTTTAACAACCCGCTCGCCAGCAGGCTGGGCCCGAGGACGTTCTGGTCCTCTTTCCAACTTTCAGATCCAGGTCCTCCAGATCGAGCTCTGGGGCCAGGCTTGTGATGTCGCCACGGGGCGCCTTATCCCAACGTCGAGACCCCGCCATTTCCCCCTACGCACGGGATCCCAGCCCCACAGGGGCATTGACCGCGACATCGATTCATCGGAGTCGGAGTCGGAGCTGGAGATCCACATCCCCGGGTTCGTACAAGTGTGA";
//    y="ATGCCCACCAACTACGAAGACCGCAACTACTGGCATCAGCGGTTTGCGTCTGAGACATCGTTCGAATGGCTGGCCTCGTCTGAGCAATTTCTGGAGCTCTTTGCGCTCTATCTCAGACCACTTCCTAAAACTGCGAAAATTCTCCATCTCGGCTCCGGCACCAGCGACTTGCACAACCATCTGAGAGATTGTGGGTTTAGTAATGTCACAAATGTCGACTACGAGCCACTTGCTCTCGAGCGAGGTCAGGAGCTTGAACGGAAGCGGTTTGGGGATGTCAAGACAACCTACATAGTCAACGACGCGACCAAGATGGATCTACCTGACAAGTATAGAGTCTTTATCGACAAGTCCACCTCTGATGCTATCGCATGTGGTGGACACCAGGCTGTTTCCCTGCTTGCTGAAGCGATTCGCCGTCACATTGAAGACGATGGCTTGTGGCTATCACTCAGTTTCTCTCCATCACGTTACGAAGGGGTTAAAACACTTTTCGATGTTGAACTTGTCAGCAAGTTGCCAACGCCGAAGCTTAATCCATACGAGCCGGACATCTACTATTATGCCTATGCGCTGAGACCAAAACCTTGA";

    int i = x.length();
    int j = y.length();

    double match=2.0;
    double change=-.5;
    double del=-1.0;

    if(argc > 4){
       for(int a=4;a<argc;a++){
          if(strcmp(argv[a],"-m") == 0){
            match = atof(argv[a+1]);
            a++;
           }

          else if(strcmp(argv[a],"-c") == 0){
            change = atof(argv[a+1]);
            a++;
          }

          else if(strcmp(argv[a],"-d") == 0){
            del = atof(argv[a+1]);
            a++;
          }
       }
    }

    //double Matrix[i+1][j+1];
    vector<vector<double> > Matrix(i+1, vector<double>(j+1,DBL_MAX));

    for(int a=0;a<=i;a++){
        Matrix[a][0] = a*del;
    }
    for(int b=0;b<=j;b++){
        Matrix[0][b] = b*del;
    }


    double leftMatrix;
    double topMatrix;
    double diagonalMatrix;

   //b=x, a=y
   for (int a = 1; a<= j; a++){
       for(int b=1;b<=i;b++){
            leftMatrix=Matrix[b-1][a];
            topMatrix=Matrix[b][a-1];
            diagonalMatrix=Matrix[b-1][a-1];
            Matrix[b][a] = compute(b,a, leftMatrix, topMatrix, diagonalMatrix,x,y,match, change, del);
        }
    }

    cout<< Matrix[i][j]<<endl;
    return 0;
 }