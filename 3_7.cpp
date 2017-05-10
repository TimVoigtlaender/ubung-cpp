#include <iostream>
#include <cmath>
using namespace std;

int main() {

double number1, number2, number3, mitte;

cout << "Nummer 1?" << endl;  																	// eingabe der Zahlen.
cin >> number1;
cout << "Nummer 2?" << endl;  
cin >> number2;
cout << "Nummer 3?" << endl;  
cin >> number3;

if( (number1<number2 and number2<number3) or (number1>number2 and number2>number3)){			// falls die zweite Zahl die mittlere ist.
	cout << "Die mittlere Zahl ist Nummer 2 mit dem Wert: " << number2 << endl;					// ausgabe der zweiten Zahl.
} 
else{
	if( (number3<number1 and number1<number2) or (number3>number1 and number1>number2)){		// falls die erste Zahl die mittlere ist.
		cout << "Die mittlere Zahl ist Nummer 1 mit dem Wert: " << number1 << endl;				// ausgabe der ersten Zahl.
	} 
	else{
		if( (number2<number3 and number3<number1) or (number2>number3 and number3>number1)){	// falls die dritte Zahl die mittlere ist.
			cout << "Die mittlere Zahl ist Nummer 3 mit dem Wert: " << number3 << endl;			// ausgabe der dritten Zahl.
		} 
		else{																					// falls keine Zahl die mittlere ist.
			cout << "Es gibt keine mittlere Zahl." << endl;
		}
  	}
}
  return(0);
}
