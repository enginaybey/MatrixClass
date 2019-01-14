#ifndef MATRIX_H_
#define MATRIX_H_

namespace mtrx
{
template <class T> 

class matrix {
private: 
	int n;
	int m;
	T **p;
	
public:
	matrix(){n=0; m=0;}
	matrix(int N, int M){
        n=N;
        m=M;
        p=new T*[n]; //allocate n rows
        for (int i=0;i<n;i++) {
            p[i]=new T[m]; //allocate m columns for each row
        }
    }
    void setmatrix(){
        double r=0.0;
		for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
			p[i][j]=(T)(r+1.1);
            r=r+1.0;	
            }
		}
	}
	
	int getn(){
           return n;
    }
    int getm(){
           return m;
    }
    T getitem(int a,int b){
           return p[a][b];
    }
    matrix(const matrix& c){
        n=c.n;
        m=c.m;
        this->p=new T*[n]; //allocate n rows
        for (int i=0;i<n;i++) {
            this->p[i]=new T[m]; //allocate m columns for each row
        }
        for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
			this->p[i][j]=c.p[i][j] ;
            }	
		}
    }	
    matrix<T>& operator=(const matrix& c){
        n=c.n;
        m=c.m;
        this->p=new T*[n]; //allocate n rows
        for (int i=0;i<n;i++) {
            this->p[i]=new T[m]; //allocate m columns for each row
        }
        for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
			this->p[i][j]=c.p[i][j] ;
            }	
		}
		return *this;
    }
    matrix<T>& copy(matrix& c){
        n=c.n;
        m=c.m;
        this->p=new T*[n]; //allocate n rows
        for (int i=0;i<n;i++) {
            this->p[i]=new T[m]; //allocate m columns for each row
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
			this->p[i][j]=c.p[i][j] ;
            }	
		}
		return *this;
    }

// +, -, * (as dot product) operators between matrix and matrix.
    matrix<T> operator+(matrix& b) {
           int n=b.getn();
           int m=b.getm();
           matrix f(n,m);
           for (int i=0;i<n;i++){
               for (int j=0;j<m;j++){
               f.p[i][j]=this->p[i][j] + b.p[i][j];
               }
           }
           return f;
    }
    matrix<T> operator-(matrix& b) {
           int n=b.getn();
           int m=b.getm();
           matrix f(n,m);
           for (int i=0;i<n;i++){
               for (int j=0;j<m;j++){
               f.p[i][j]=this->p[i][j] - b.p[i][j];
               }
           }
           return f;
    }
    
    matrix<T> operator*(matrix& b) {
           int n=b.getn();
           int m=b.getm();
           matrix c(n,m);
           for (int i=0;i<n;i++){
               for (int k=0;k<n;k++){
                   for (int j=0;j<n;j++){
               c.p[i][j] += this->p[i][k] * b.p[k][j];
                       }
               }
           }
           return c;
    }
    
	~matrix(){
              for (int i=0;i<n;i++) {
              delete [] p[i]; //deallocate columns for each row
                     }
              delete [] p; //deallocate rows
              }             
 };
}/*namespace mtrx*/
#endif
