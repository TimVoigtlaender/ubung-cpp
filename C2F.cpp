																					// Rechne Farenheit zu Celsim um
#include <cmath>
#include <iostream>
using namespace std;
float tf,tc; 
int main() {
	cout << "Bitte Grad in Fahrenheit eingeben:";
	cin >> tc; 																		// Frage nach Temperatur in Fahrenheit
	tf = 9*tc/5 +32; 																// Umrechnung in Celsius
	cout << tc << " Grad Fahrenheit entprechen " << tf << " Grad Celsius." << endl;	// Ausgabe der Temperatur in Celsius
	return(0);
}
