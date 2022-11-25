/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/


#include "matrix.h"
#include "cnn.h"
#include <iostream>
#include <fstream>

typedef float** matrix;
using namespace std;


int main(int argc, char *argv[]){

    matrix M;
    matrix K;
    int dim;
    int dimk;

    if(argc!=3){
        cout<<"Usage: ./main.exe <matrixfile> <kernelfile> \n";
        exit(0);
    }


    ifstream matrix_;
    matrix_.open(argv[1],ios::in);
    if(matrix_.is_open()){
        M = read_data_file(matrix_,dim);
    }    
    matrix_.close();
    cout<<"Matrix dimension: "<<dim<<endl;


    ifstream kernel_(argv[2],ios::in);
    if(kernel_.is_open()){
        K = read_data_file(kernel_,dimk);
    }    
    kernel_.close();
    cout<<"Kernel dimension: "<<dimk<<endl;


//-------------MAX_POOL----------------------
    int dimb;
    matrix B = max_pool(M,dim,dimb);
    char file1[] = "results/max_pool.txt";
    print_matrix_file(B,dimb,file1);
    cout<<"max_pool dimensions: "<<dimb<<endl;


//--------------AVG_POOL---------------------
    int dimc;
    matrix C = avg_pool(M,dim,dimc);
    char file2[] = "results/avg_pool.txt";
    print_matrix_file(C,dimc,file2);
    cout<<"avg_pool dimensions: "<<dimc<<endl;


//--------------RELU6-----------------------
    reLu6(M,dim);
    char file3[] = "results/reLu6.txt";
    print_matrix_file(M,dim,file3);


//---------------CONVOLUTION_ZERO----------------
    matrix F = convolution_zero(M,dim,K,dimk);
    char file4[] = "results/convolution.txt";
    print_matrix_file(F,dim,file4);

    return 0;    
}