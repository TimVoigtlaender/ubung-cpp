/*Berechnen einer fakult�t*/
#include <cmath>
#include <iostream>
using namespace std;
int check,count;
double output=1;
float input;
int main(){
	cout << "Zahl? " << endl;
	cin >> input;
 	check = input;
	if (check<0 or cin.fail()==1 or check!=input){ 	// Entscheiden ob der gesuchte Wert existiert. Schlie�t negative und Kommazahlen und Buchstaben aus.
		cout << "Existiert nicht!" << endl;			// Gibt das Fehlermeldung aus.
	}
	else{	 										// Berechnet die Fakult�t.
		for (count = 1 ;count <= check; ++count){
			output *= count;
		}
		cout << "Fakultaet(" << input << ")= " << output << endl; 					// Gibt das Ergebnis aus.
	}
	return(0);
}
