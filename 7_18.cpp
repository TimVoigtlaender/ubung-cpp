#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	int length, zahl=0;
	char ein[50];
	
	cout << "Bitte Zahl eingeben (M,D,C,L,X,V,I)" << endl;																		// Eingabe der römischen Zahl.
	cin >> ein;
	length = strlen(ein);
	
	int wert[length], faktor[length+1];
	wert[length]=0;
	
	for(int i=0; i<length; i++){																								// Ermittelung der "rohen" Zahlen.
		if(ein[i]=='M'){
			wert[i] = 1000;
		}
		else if(ein[i]=='D'){
			wert[i] = 500;
		}
		else if(ein[i]=='C'){
			wert[i] = 100;
		}
		else if(ein[i]=='L'){
			wert[i] = 50;
		}
		else if(ein[i]=='X'){
			wert[i] = 10;
		}
		else if(ein[i]=='V'){
			wert[i] = 5;
		}
		else if(ein[i]=='I'){
			wert[i] = 1;
		}
		
//		cout << wert[i] << endl;
	}
	for(int i=0; i<length; i++){																								// Überprüfung ob Wert abgezogen werden muss.
		if(wert[i]<wert[i+1]){
			zahl -= wert[i];
		}
		else{
			zahl += wert[i];
		}
	}
	
	cout << "Die Zahl " << ein << " hat den Wert " << zahl;																		// Ausgabe der Zahl.
	
return 0;
}
