/*Berechnen von P(N)*/
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
	if (check<1 or cin.fail()==1 or check!=input){ 			// Entscheiden ob der gesuchte Wert existiert. Schließt N<1 und Kommazahlen und Buchstaben aus.
		cout << "Existiert nicht!" << endl;					// Gibt die Fehlermeldung aus.
	}
	else{	 												// Berechnet P(N).
		for (count = 1 ;count <= check; ++count){
			output *= 3*count-1;
			cout << output << endl;
		}
		cout << "P(" << input << ")=" << output << endl; 	// Gibt das Ergebnis aus.
	}
	return(0);
}
