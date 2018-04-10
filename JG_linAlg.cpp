#include <iostream>
#include <cstdlib>
using namespace std;

double **matrix_product(double **ma,int fa, int ca, double **mb, int fb, int cb);
double **get_Matrix(int M, int N);
int main(){
	/*
	//esto es un vector de 10 componentes
	double *a = new double[10];
	//matriz
	double **mat = new double*[4];
	int i;
	for(i=0;i<4;i++){
		mat[i]=new double[5];
	}
	int j;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			mat[i][j] = i*j;
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	//entrada de filas y columnbas de A y B
	int fa;
	cout<<"Ingrese el numero de filas de la matriz A: "<<endl;
	cin>>fa;
	int ca;
	cout<<"Ingrese el numero de columnas de la matriz A: "<<endl;
	cin>>ca;
	int fb;
	cout<<"Ingrese el numero de filas de la matriz B: "<<endl;
	cin>>fb;
	int cb;
	cout<<"Ingrese el numero de columnas de la matriz B: "<<endl;
	cin>>cb;
	//evalua si si se pueden multiplicar
	if(fb != ca){
		cout<<"La cantidad de filas de B debe ser igual a la cantidad de columnas de A"<<endl;
	}else{
		cout<<"Ingreso matriz A: "<<endl;
		double **A =get_Matrix(fa, ca);
		cout<<"Ingreso matriz B: "<<endl;
		double **B =get_Matrix(fb, cb);
		
		//multiplico las matrices e impresion final:
		double **matrizfinal=matrix_product(A,fa,ca,B,fb,cb);
		cout<<"El resultado del producto de A y B es: "<<endl;
		int i;
		int j;
		for(i=0;i<fa;i++){
			for(j=0;j<cb;j++){
				cout<<matrizfinal[i][j]<<" ";
			}
			cout<<endl;
		}
	} 
	
	return 0;
}

double **matrix_product(double **ma,int fa, int ca, double **mb, int fb, int cb){
	int i;
	int j;
	//declaro matriz respuesta con fa filas
	double **mAns=new double*[fa];
	double suma;
	int k;
	//cada fila tiene cb elementos
	for(i=0;i<fa;i++){
		mAns[i]=new double[cb];
	}
	//lleno la matriz respuesta. cada elemento es el producto punto entre la fila i de a y la columna j de b
	for(i=0;i<fa;i++){
		for(j=0; j<cb; j++){
			suma=0;
			for(k=0;k<ca;k++){
				suma +=ma[i][k]*mb[k][j] ;
			}
			mAns[i][j]=suma;
		}
	}
	return mAns;
}

double **get_Matrix(int M, int N){
	//imprimo M y N
	cout<<"El numero de filas es: "<<M<<endl;
	cout<<"El numero de columnas es: "<<N<<endl; 
	//declaro matriz de M filas
	double **mNew=new double*[M];
	int i;
	//recorro las filas declarando vectores de N elementos en cada fila
	for(i=0;i<M;i++){
		mNew[i]=new double[N];
	}
	int j;
	//recorrido que pide que ingrese los valores 1 por 1
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			cout<<"Ingrese el valor en fila "<<i<<" columna "<<j<<endl;
			cin>>mNew[i][j];
		}
	}
	//imprime la matriz recien llenada
	cout<<"La matriz ingresada es:"<<endl;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			cout<<mNew[i][j]<<" ";
		}
		cout<<endl;
	}
	return mNew;
}


