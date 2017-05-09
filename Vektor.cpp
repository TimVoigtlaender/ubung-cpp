#include <cmath>
#include <iostream>
using namespace std;
int Zeile, Spalte;
int mat[4][3] ={1,2,3, 4,5,6, 7,8,9, 10,11,12};
int main(){
	cout << "Zeile? " << endl;
	cin >> Zeile;
	cout << "Spalte? " << endl;
	cin >> Spalte;
	cout << "Der Wert in Zeile " << Zeile << " und Spalte " << Spalte << " der Matrix ist " << mat[Zeile][Spalte]<< "." << endl;
	return(0);
}

