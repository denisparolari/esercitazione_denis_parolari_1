/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#ifndef MAXPOOL_H
#define MAXPOOL_H

#include <iostream>
#include "matrix.h"

using namespace std;

typedef float **matrix;

//const int h=128;

matrix max_pool(const matrix M, const int dim, int &dimmax);
matrix avg_pool(const matrix M, const int &dim,int &dimavg);
matrix reLu6(const matrix M, const int dim);
matrix convolution_zero(matrix mat, const int dim, const matrix ker, const int dimk);


#endif