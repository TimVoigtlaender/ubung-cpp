/*Berechnen einer fakultät*/
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
	if (check<0 or cin.fail()==1 or check!=input){ 	// Entscheiden ob der gesuchte Wert existiert. Schließt negative und Kommazahlen und Buchstaben aus.
		cout << "Existiert nicht!" << endl;			// Gibt das Fehlermeldung aus.
	}
	else{	 										// Berechnet die Fakultät.
		for (count = 1 ;count <= check; ++count){
			output *= count;
		}
		cout << "Fakultaet(" << input << ")= " << output << endl; 					// Gibt das Ergebnis aus.
	}
	return(0);
}
