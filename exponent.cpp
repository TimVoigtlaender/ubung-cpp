																		// Berechne e hoch eine Zahl. Möglicher Bereich -103 bis 88
#include <cmath>
#include <iostream>
using namespace std;
double number, enumber;
int main() {
	cout << "Bitte Zahl eingeben:";
	cin >> number; 														// Frage nach Zahl
	enumber = exp(number);												// Berechnung der neuen Zahl
	cout << "e hoch " << number << " ist " << enumber << "." << endl;	// Ausgabe der neu berechneten Zahl
	return(0);	
}
