#include <iostream>
#include <iomanip>

using namespace std;

void metodo_lu(int mat[][100], int n) {
	// Matrices cuadras de nxn
	int lower [n][n];
	int upper [n][n];
	
	// Descomposicion de la matriz 
	for(int i = 0; i < n; i++) {
		
		// Matriz Upper
		for(int k = i; k < n; k++) {
			
			int suma = 0;
			for(int j = 0; j < i; j++) {
				suma += (lower[i][j] * upper[j][k]);
			}
			upper[i][k] = mat[i][k] - suma;
		}
		
		// Matriz Lower
		for(int k = i; k < n; k++) {
			
			if(i == k) {
				lower[i][i] = 1;
			} else {
				int suma = 0;
				for(int j = 0; j < i; j++) {
					suma += (lower[k][j] * upper[j][i]);
				}
				lower[k][i] = (mat[k][i] - suma) / upper[i][i];
			}
		}
	}
	
	cout<<setw(6)<<"      Lower Triangular"<<setw(32)<<"    Upper Triangular"<<endl;
	for(int  i = 0; i < n; i++) {
		lower[0][2] = 0;
		lower[1][2] = 0;
		for(int j = 0; j < n; j++) {
			cout<<setw(6)<<lower[i][j]<<"\t";
		}
		cout<<"\t";
		upper[2][0] = 0;
		upper[2][1] = 0;
		for(int j = 0; j < n; j++) {
			cout<<setw(6)<<upper[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	// Multipliar matriz
	int result [n][n];
	
	for(int i = 0; i < n; i++) {
		int aux = 0;
		while(aux < n) {
			int acomulador = 0;
			for(int j = 0; j < n; j++) {
				acomulador = acomulador + ( (lower[i][j]) * (upper[j][aux]) );
			}
			result[i][aux] = acomulador;
			aux+=1;
		}
	}
	
	// Imprimir resultado del producto
	cout<<setw(6)<<"           Result"<<endl;
	for(int  i = 0; i < n; i++) {
		
		for(int j = 0; j < n; j++) {
			cout<<setw(6)<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main() {
	
	int matriz[100][100];
	
	//Almacenando los valores de la matriz
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout<<"Digite el valor para la posicion ["<<i<<"]["<<j<<"] = ";
			cin>>matriz[i][j];
		}
	}
	
	cout<<setw(6)<<"           Matriz"<<endl;
	for(int  i = 0; i < 3; i++) {
		
		for(int j = 0; j < 3; j++) {
			cout<<setw(6)<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	metodo_lu(matriz, 3);
	
	return 0;
}
