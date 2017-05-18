#include <iostream>
#include <fstream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	char filename[50];																			// Variablen definieren.
	double mat[3][3];																			
	double sum[3]={0,0,0};
	double number, colsum;
	
	cout << "Bitte Dateiname eingeben: ";														// Nach Datei fragen.
	ifstream bucky;
	cin.getline(filename, 50);
	bucky.open(filename);
	
	if(!bucky.is_open()){																		// Überprüfen ob die Datei existiert.
		cout << "Keine solche Datei gefunden!";
		exit(EXIT_FAILURE);
	}
	
	bucky >> number;																			// Matrix aus Datei auslesen.
	cout << endl << setw(10);
	for(int i=0; bucky.good(); i++){
		for(int j=0; j<=2; j++){
			cout << number << setw(10);
			mat[i][j] = number;
			bucky >> number;
		}
		cout << endl << endl;		
	}
	
																								// Determinante berechnen.
	double det = mat[0][0]*mat[1][1]*mat[2][2]+mat[0][1]*mat[1][2]*mat[2][0]+mat[0][2]*mat[1][0]*mat[2][1]-mat[0][2]*mat[1][1]*mat[2][0]-mat[0][0]*mat[1][2]*mat[2][1]-mat[0][1]*mat[1][0]*mat[2][2];
	
	for(int j=0; j<=2; j++){																	// Spaltensummen berechnen.
		for(int i=0; i<=2; i++){
			if(mat[i][j]<0){
				sum[j] -= mat[i][j];
			}
			else{
				sum[j] += mat[i][j];
			}
		}
	}
	
	cout << "Die Determinante der Matrix ist: " << det << endl;									// Determinante ausgeben.
	cout << "Und die Spaltensummennorm der Matrix ist: " << max(max(sum[0], sum[1]), sum[2]);	// Spaltensummennorm ausgeben.
	
	
	return 0;
}
