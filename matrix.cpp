/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#include "matrix.h"

void print_matrix_file(matrix mat, const int dim, char*file){
    fstream myfile;
    myfile.open(file,ios::out);
    if(myfile.is_open()){
        for(int i=0;i<dim;i++){
            myfile<<"|";
            for(int j=0;j<dim;j++){
                myfile<<setw(10)<<mat[i][j];
            }
            myfile<<" |"<<endl;
        }
    }
    myfile.close();
    return;
}

matrix alloca_matrix(const int dim){
    matrix mat=new float*[dim];
    for(int i=0;i<dim;i++){
        mat[i] = new float[dim];
    }
    return mat;
}

matrix read_data_file(ifstream& file_, int &dim){
    dim = dim_matrix(file_);
    file_.clear();
    file_.seekg(0, ios::beg);
    matrix num;
    num = alloca_matrix(dim);

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            file_>>num[i][j];
        }
    }
    return num;

}

int dim_matrix(ifstream& file_){
    int dim=0;
    float num=0;
    while(file_>>num){
        dim++;
    }
    return sqrt(dim);
}