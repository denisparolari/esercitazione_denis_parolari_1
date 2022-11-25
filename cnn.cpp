/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#include "cnn.h"

matrix max_pool(const matrix M, const int dim, int &dimmax){
    float max,max1,max2;
    dimmax = dim/2;
    int r=0,c=0;

    matrix MP =alloca_matrix(dimmax);

    for(int i=0;i<dim;i+=2){
        for(int j=0;j<dim;j+=2){

            if(M[i][j]>M[i][j+1]){
                max1=M[i][j];
                
            }else{max1=M[i][j+1];}

            if(M[i+1][j]>M[i+1][j+1]){
                max2=M[i+1][j];
                
            }else{max2=M[i+1][j+1];}

            if(max1>max2){max=max1;}
            else{max=max2;}

            MP[r][c]=max;
            c++;           
        }
        r++;
        c=0;
    }
    return MP;
    
}

matrix avg_pool(const matrix M, const int &dim, int &dimavg){
    dimavg=dim/2;
    float mean;
    int r=0,c=0;

    matrix H = alloca_matrix(dimavg);

    for(int i=0;i<dim;i+=2){
        for(int j=0;j<dim;j+=2){
            mean = 0;
            mean=(M[i][j]+M[i][j+1]+M[i+1][j]+M[i+1][j+1])/4;
            H[r][c]=mean;
            c++;
        }
        r++;
        c=0;
    }
    return H;
}

matrix reLu6(const matrix M, const int dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){

            if(M[i][j]>6){M[i][j]=6;}             
            else if(M[i][j]<0){M[i][j]=0;}           
        }
    }
    return M;
    
}

matrix convolution_zero(matrix M, const int dim, const matrix K, const int dimk){
    float conv_tmp=0;
    int r=0,c=0;
    matrix conv = alloca_matrix(dim);

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            conv_tmp=0;
            for(int r=0;r<dimk;r++){
                for(int c=0;c<dimk;c++){
                    if((i+r)<dim && (j+c)<dim){
                        conv_tmp+=(M[i+r][j+c]*K[r][c]);
                    }
                    else{conv_tmp+=0;}
                }
            }
            conv[i][j]=conv_tmp;
        }
    }
    return conv;
}