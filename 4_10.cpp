#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cstdlib>

using namespace std;
int main() {
	long int inputint, amax, check, min=1, mox=100000000;
	long double input;
	cout << "Bitte ganze Zahl von " << min << " bis " << mox << " eingeben." << endl << "a(0)= ";
	cin >> input;
 	check = input;
	if (min>input or input>mox or cin.fail()==1 or check!=input){ 			// Entscheiden ob der gesuchte Wert existiert. Schlieﬂt N<1 und Kommazahlen und Buchstaben aus.
		cout << "Falsche Eingabe!" << endl;									// Gibt die Fehlermeldung aus.
		exit(EXIT_FAILURE);
	}
	inputint = check;
	amax = inputint;
	for(int n=1; check!=1; n++){										// L‰sst Programm laufen bis 1 erreicht wurde.
		if ((check % 2) == 0){											// a(n) gerade
			check *= 1./2;
		}
		else{															// a(n) ungerade
			check = 3*check+1;
		}
		amax = max(amax, check);										// grˆﬂtes Folgenglied ermitteln.
		cout << "a(" << n << ")= " << check <<endl;						// ausgabe der Schritte.
	}
		cout << "Das maximale a(n) bei der Startzahl " << inputint << " ist " << amax;			// Maximales Folgenglied ausgeben.
  return(0);
}
