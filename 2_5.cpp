/*Berechnen von P(N)*/
#include <cmath>
#include <iostream>
using namespace std;
int count;
double input,epsilon=1, epsilon2=1; 
int main(){
	cout << "Zahl? " << endl;
	cin >> input;
	if (cin.fail()==1){ 														// Entscheiden ob der gesuchte Wert existiert. Schließt Buchstaben aus.
		cout << "Existiert nicht!" << endl;										// Gibt die Fehlermeldung aus.
	}
	else{																
		for (count = 1; input+epsilon != input; ++count){				
		epsilon2 = epsilon;														// Merken von 2*epsilon
		epsilon = epsilon/float(2);												// Halbieren von epsilon
		}
		cout << "Der lezte Wert, bei dem zwischen " << input << "+epsilon und " << 
		input << " unterschieden werden kann ist " << epsilon2 << "." <<endl;	// Ausgabe des gesuchten Werts.
	}
	return(0);
}
