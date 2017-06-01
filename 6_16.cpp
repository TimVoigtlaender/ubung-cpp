#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	char filename[50], code;																	// Variablen definieren.
	double number, wert=1, prod=1, fvx=0;
	int wertn = 12;
	double x[wertn], fx[wertn];
	
	ifstream bucky;
	bucky.open("a16-interpol.dat");
	
	for(int k=0; k<wertn; k++){
		bucky >> number;
		x[k] = number;
		bucky >> number;
		fx[k] = number;
	}
	
	bucky.close();
	ofstream myfile;
	myfile.open("a16-interpol-res.dat");
	cout << "Bitte x-Wert eingeben:" << endl;
	
	for(int m=0; wert!=0; m++){
		cin >> wert;
			for(int i=0; i<wertn; i++){
				for(int k=0; k<wertn; k++){
					if(i!=k){
						prod *= (wert-x[k])/(x[i]-x[k]);
					}
				}
				fvx += fx[i]*prod;
				prod = 1;
			}
		cout << "f(" << wert << ")=" << fvx << endl;
		myfile << wert << setw(10) << fvx << endl;	
		fvx = 0;
	}
	myfile.close();
	return 0;
}
