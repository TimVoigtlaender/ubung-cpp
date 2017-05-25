#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	double number, sum, maximum, swapb;
	int length, diagonal, pivot;
	char filename[50];																			// Variablen definieren.
	
	cout << "Bitte Dateiname eingeben: ";														// Nach Datei fragen. a13-lgs1.dat, ...
	ifstream bucky;
	cin.getline(filename, 50);
	bucky.open(filename);
	
	if(!bucky.is_open()){																		// Überprüfen ob die Datei existiert.
		cout << "Keine solche Datei gefunden!";													// Gibt die Fehlermeldung aus.
		exit(EXIT_FAILURE);
	}
	
	bucky >> number;																			
	length = number;																			// Größe der Matrix auslesen.
	
	double mat[length][length], mat2[length][length];	
	double sol[length], x[length], rech[length], swapping[length];
	
	for(int i=0; i<length; i++){																// Matrix aus Datei auslesen.
		for(int j=0; j<length; j++){
			bucky >> number;
			mat[i][j] = number;
			mat2[i][j] = number;
		}		
	}
	
	for(int i=0; i<length; i++){																// Vektor aus Datei auslesen.
		bucky >> number;
		sol[i] = number;
	}
	
	cout << "Ohne Spaltenpivotisierung: 0" << endl << "Mit Spaltenpivotisierung: 1" << endl;	// Abfrage ob Spaltenpivotisierung genutzt werden soll.
	cin >> pivot;
	if (pivot != (1 or 0)){ 																	// Entscheiden Eingabe Korrekt ist.
		cout << "Falsche Eingabe!" << endl;														// Gibt die Fehlermeldung aus.
		exit(EXIT_FAILURE);
	}
	
	
	
	for(int i=0; i<length; i++){																// Gleichung darstellen.
	 	for(int j=0; j<length; j++){
			cout << setw(9) << mat[i][j];
	 	}
	 	
		if(i==length/2.-0.5){
			cout << setw(5) << "*" << setw(6);
		}
		else{
			cout << setw(11);
		}
		
		cout << "x[" << i << "]";
		
		if(i==length/2.-0.5){
			cout << setw(5) << "=" << setw(9);
		}
		else{
			cout << setw(14);
		}
		
		cout << sol[i] << endl;
		
		if(i==length/2.-1){
			cout << setw(9*length+5) << "*" << setw(13) << "=" << endl;
		}
		else{
			cout << endl;	
		}
	}
	
	cout  << "----------------------------------------------------------------------------------------------------------" << endl << endl;
	
	for(int i=length-1; i>=1; i--){																// In Dreiecksform umwandeln.
		diagonal = length-i-1;
		for(int j=length-1; j>=length-i; j--){
			if(pivot==1){																		// Spaltenpivotisierung wird durchgeführt.
				for(int k=j; k>=diagonal; k--){													
					if(fabs(mat[k][i])>fabs(mat[diagonal][i])){									
						swapb = sol[k];
						sol[k] = sol[diagonal];
						sol[diagonal] = swapb;
						for(int s=0; s<length; s++){
							swapping[s] = mat[k][s];
							mat[k][s] = mat[diagonal][s];
							mat[diagonal][s] = swapping[s];
						}
					}
				}
			}
			float c = mat[j][i]/mat[diagonal][i];
			sol[j] = sol[j]-c*sol[diagonal];
			for(int k=0; k<length; k++){
				mat[j][k] = mat[j][k]-c*mat[diagonal][k];
			}
		
		}
	}

	for(int n=0; n<length; n++){																// Werte von x[i] bestimmen.
		sum = 0;
		for(int k=0; k<n; k++){
			sum +=mat[length-n-1][k]*x[k];
		}
		x[n]=(sol[length-n-1]-sum)/mat[length-n-1][n];
	}

	for(int n=0; n<length; n++){																// Lösung ausgeben.
		cout << "x[" << n << "]= " << x[n] << endl;
	}

	cout << endl << "----------------------------------------------------------------------------------------------------------" << endl << endl;

	for(int n=0; n<length; n++){																// Lösung überprüfen.
		for(int i=0; i<length; i++){
			rech[n] += mat2[n][i]*x[i];
		}
	}

	for(int i=0; i<length; i++){																// Gleichung mit errechneter Lösung.
	 	for(int j=0; j<length; j++){
			cout << setw(9) << mat2[i][j];
	 	}
	 	
		if(i==length/2.-0.5){
			cout << setw(5) << "*" << setw(6);
		}
		else{
			cout << setw(11);
		}
		
		cout << "x[" << i << "]";
		
		if(i==length/2.-0.5){
			cout << setw(5) << "=" << setw(9);
		}
		else{
			cout << setw(14);
		}
		
		cout << rech[i] << endl;
		
		if(i==length/2.-1){
			cout << setw(9*length+5) << "*" << setw(13) << "=" << endl;
		}
		else{
			cout << endl;	
		}
	}

	return 0;
}
