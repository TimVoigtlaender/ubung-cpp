																					// Rechne Farenheit zu Celsim um
#include <cmath>
#include <iostream>
using namespace std;
float tf,tc; 
int main() {
	cout << "Bitte Grad in Fahrenheit eingeben:";
	cin >> tf; 																		// Frage nach Temperatur in Fahrenheit
	tc = 5*(tf-32)/9; 																// Umrechnung in Celsius
	cout << tf << " Grad Fahrenheit entprechen " << tc << " Grad Celsius." << endl;	// Ausgabe der Temperatur in Celsius
	return(0);
}
