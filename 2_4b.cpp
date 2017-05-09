/*Berechnen von P(N)*/
#include <cmath>
#include <iostream>
using namespace std;
int check,count,count2;
double output=0,output2=0;
float input;
int main(){
	cout << "Zahl? " << endl;
	cin >> input;
 	check = input;
	if (check<1 or cin.fail()==1 or check!=input){ 			// Entscheiden ob der gesuchte Wert existiert. Schließt N<1 und Kommazahlen und Buchstaben aus.
		cout << "Existiert nicht!" << endl;					// Gibt die Fehlermeldung aus.
	}
	else{	 												// Berechnet P(N).
		for (count = 1; count <= check; ++count){			// Äußere Summe
			for (count2 = 1; count2 <= count; ++count2){	// Innere Summe
			output = output+(double)1/(double)(count2*count);
			}
		output2 = output2+output;
		output = 0;											// Zurücksetzen der innren Summe
		cout << output2 << endl;							// Zwischenergebnis ausgeben
		}
		cout << "S(" << input << ")=" << output2 << endl; 	// Gibt das Ergebnis aus.
	}
	return(0);
}
