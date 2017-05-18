#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	long int check, min=1, max=100000000;
	long double input;
	cout << "Bitte ganze Zahl von " << min << " bis " << max << " eingeben." << endl << "a(0)= ";
	cin >> input;
 	check = input;
	if (min>input or input>max or cin.fail()==1 or check!=input){ 			// Entscheiden ob der gesuchte Wert existiert. Schlie�t N<1 und Kommazahlen und Buchstaben aus.
		cout << "Falsche Eingabe!" << endl;									// Gibt die Fehlermeldung aus.
	}
	else{
		for(int n=1; check!=1; n++){										// L�sst Programm laufen bis 1 erreicht wurde.
			if ((check % 2) == 0){											// a(n) gerade
				check *= 1./2;
			}
			else{															// a(n) ungerade
				check = 3*check+1;
			}
			cout << "a(" << n << ")= " << check <<endl;						// ausgabe der Schritte.
		}
	}
  return(0);
}