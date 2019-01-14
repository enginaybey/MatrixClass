//============================================================================
// Name        : matrix_main.cpp
// Author      : Engin Aybey
// Version     : 1.2.0
// Copyright   : All rights reserved.
// Description : Matrix Class
//============================================================================

#include <iostream>
#include <cstdlib>
#include "matrix.h"

using namespace std;
using namespace mtrx;

int main(){
    int j;
    int i;
    int r=3; //# of rows
    int c=3; //# of columns
    # define my_type double
    matrix<my_type> x(r,c);
    
    x.setmatrix(); // the matrix
    matrix<my_type> y(x);
    //matrix<my_type> y=x;
    //matrix<my_type> y;
    //y.copy(x);// the copy of the matrix     
    //cout<<&x<<endl;
    //cout<<&y<<endl;

        cout<<"===================O================"<<endl;
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
        cout <<"x["<<i+1<<"]["<<j+1<<"] = "<< x.getitem(i,j)<<endl;
        }
    }
        cout<<"===================O================"<<endl;
    for (i=0;i<r;i++){    
        for (j=0;j<c;j++){
        cout <<"y["<<i+1<<"]["<<j+1<<"] = "<< y.getitem(i,j)<<endl;
        
		}
    }
        cout<<"===================O================"<<endl;
        
        
// +, -, * (as dot product) operators between matrix and matrix.
        matrix <my_type>islem1(r,c);
        islem1=x+y;
    for (i=0;i<r;i++){ 
        for (j=0;j<c;j++){
        cout <<"x["<<i+1<<"]["<<j+1<<"] +"<<" y["<<i+1<<"]["<<j+1<<"] = "<<islem1.getitem(i,j)<<endl;
        }
    }
        cout<<"===================O================"<<endl;
        
        matrix <my_type> islem2(r,c);
        islem2=x-y;
    for (i=0;i<r;i++){ 
        for (j=0;j<c;j++){
        cout <<"x["<<i+1<<"]["<<j+1<<"] -"<<" y["<<i+1<<"]["<<j+1<<"] = "<<islem2.getitem(i,j)<<endl;
        }
    }
        cout<<"===================O================"<<endl;

        matrix <my_type> islem3(r,c);
        islem3=x*y;
        cout<<"the dot product of two vectors: "<<endl;
    for (i=0;i<r;i++){ 
        for (j=0;j<c;j++){
        cout <<"C["<<i+1<<"]["<<j+1<<"] = "<<islem3.getitem(i,j)<<endl;
        }
    }
        cout<<"===================O================"<<endl;

     return 0;  
}
