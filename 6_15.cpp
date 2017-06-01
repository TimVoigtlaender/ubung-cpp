#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	char filename[50], code;																	// Variablen definieren.
	double number;
	int count=0;
	
	cout << "Bitte Dateiname eingeben: ";														// Nach Datei fragen.
	ifstream bucky;
	cin.getline(filename, 50);
	bucky.open(filename);
	
	if(!bucky.is_open()){																		// Überprüfen ob die Datei existiert.
		cout << "Keine solche Datei gefunden!";
		exit(EXIT_FAILURE);
	}
	
	bucky >> number;
	int spalten=number;
	bucky >> number;
	int zeilen=number;	
														
	cout << endl << endl;
	
	for(int i=0; bucky.good(); i++){
		bucky >> number;
		if(number==0){																			// Entcodieren der Datei.
			code = '.';
		}
		else if(number==1){
			code = ',';
		}
		else if(number==2){
			code = '~';
		}
		else if(number==3){
			code = '=';
		}
		else if(number==4){
			code = '+';
		}
		else if(number==5){
			code = ':';
		}
		else if(number==6){
			code = '?';
		}
		else if(number==7){
			code = '$';
		}
		else if(number==8){
			code = '7';
		}
		else if(number==9){
			code = '8';
		}
		else if(number==10){
			code = 'D';
		}
		else if(number==11){
			code = 'I';
		}
		else if(number==12){
			code = 'M';
		}
		else if(number==13){
			code = 'N';
		}
		else if(number==14){
			code = 'O';
		}
		else if(number==15){
			code = 'Z';
		}
		else{																						// Fehlerausgabe falls Code nicht existiert.	
			cout << "Zeichencode existiert nicht!" << endl;
			exit(EXIT_FAILURE);
		}
		bucky >> number;
		for(int k=0; k<number; k++){
			if(count==(spalten*zeilen)){
				exit(EXIT_FAILURE);
			}
			if(count%spalten==0){																	// Umsetzung der Zeilenlänge
				cout << endl;
			}
			cout << code;
			count += 1;
		}
	}
	return 0;
}
