/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

typedef float **matrix;

//const int n=128;
void print_matrix_file(matrix mat, const int dim, char *file);
matrix alloca_matrix(const int dim);
matrix read_data_file(ifstream& file_, int &dim);
int dim_matrix(ifstream& file_);

#endif