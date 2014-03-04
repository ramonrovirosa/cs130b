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

    double left= leftMatrix + del;
    double top = topMatrix + del;
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
//        cout<<x<<endl;


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
//            cout<<y<<endl;
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
    vector<vector<double> > Matrix;
     // Set up sizes. (HEIGHT x WIDTH)
    Matrix.resize(j+1);
    for (int a = 0; a < j+1; ++a)
        Matrix[a].resize(i+1);
    cout<<x.length()<<endl;
    cout<<y.length()<<endl;

//    double Matrix[i+1][j+1];

    for(int a=0;a<=i;a++){
        Matrix[a][0] = a*del;
    }
    for(int b=0;b<=j;b++){
        Matrix[0][b] = b*del;
    }

   //b=x, a=y
   for (int a = 1; a<= j; a++){
       for(int b=1;b<=i;b++){
            double leftMatrix=Matrix[b-1][a];
            double topMatrix=Matrix[b][a-1];
            double diagonalMatrix=Matrix[b-1][a-1];

            Matrix[b][a] = compute(b,a, leftMatrix, topMatrix, diagonalMatrix,x,y,match, change, del);
        }
    }

//    for (int a=0; a<=j;a++){
//            for(int b=0; b<=i;b++){
//                if(Matrix[b][a] < -9)
//                    cout<<Matrix[b][a]<< " ";
//                else if(Matrix[b][a] < 0 || Matrix[b][a] > 9)
//                    cout<<""<<Matrix[b][a]<< "  ";
//                else
//                    cout<<" "<<Matrix[b][a]<< "  ";
//            }
//            cout<<endl;
//        }

    cout<< Matrix[i][j]<<endl;

    return 0;
 }