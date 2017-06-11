#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
	int n = 11;
	int zn = 1+n, anzwert=300;
	double number, lambda[n], mu[zn], d[zn], f, M[zn], alpha[n], beta[n], gamma[n], delta[n], wert, S, x[zn], y[zn];
	
	ifstream bucky;																				// Daten aus Datei auslesen.
	bucky.open("a16-interpol.dat");
	for(int k=0; k<zn; k++){
		bucky >> number;
		x[k] = number;
		bucky >> number;
		y[k] = number;
	}
	bucky.close();
	
	lambda[0] = 0;																				// Randbedingungen festlegen.
	mu[n] = 0;
	d[0] = 0;
	d[n] = 0;
	mu[0] = 2;
	
	for(int j=1; j<=n-1; j++){
		lambda[j] = (x[j+1]-x[j])/(x[j+1]-x[j-1]);
		mu[j] = (x[j]-x[j-1])/(x[j+1]-x[j-1]);
		d[j] = 6/(x[j+1]-x[j-1])*((y[j+1]-y[j])/(x[j+1]-x[j])-(y[j]-y[j-1])/(x[j]-x[j-1]));
	}
	for(int i=1; i<=n; i++){
		f = -mu[i]/mu[i-1];
		mu[i] = 2+f*lambda[i-1];
		d[i] += f*d[i-1];
	}
	M[n] = d[n]/mu[n];
	
	for(int i=n-1; i>=0; i--){																	// M[j] berechnen.
		M[i] = (d[i]-lambda[i]*M[i+1])/mu[i];
	}
	
	ofstream myfile;
	myfile.open("a17-interpol-res.dat");
	
	for(int k=1; k<=anzwert; k++){																// Erstellen der x-Werte.
		wert = x[0]+(x[n]-x[0])*k/anzwert;
		for(int j=0; j<=n-1; j++){
			if(wert-x[j+1]<=0 and wert-x[j]>0){
				alpha[j] = y[j];
				beta[j] = (y[j+1]-y[j])/(x[j+1]-x[j])-(2*M[j]+M[j+1])/6*(x[j+1]-x[j]);
				gamma[j] = M[j]/2;
				delta[j] = (M[j+1]-M[j])/(6*(x[j+1]-x[j]));
				S = alpha[j]+beta[j]*(wert-x[j])+gamma[j]*pow((wert-x[j]),2)+delta[j]*pow((wert-x[j]), 3);
			}																					// Berechnung der y-Werte.
		}
		cout << "f(" << wert << ")= " << S << endl;
		myfile << wert << setw(10) << S << endl;												// Abspeichern der Daten.
	}
	myfile.close();
	
	FILE *gnu = _popen("\"C:\\Program Files (x86)\\gnuplot\\bin\\gnuplot.exe\" -persist", "w");	// Ausgabe in Gnuplot.
	if (!gnu){
		return 1;
	}
	fprintf(gnu, "cd 'C:\\Users\\Tim\\Documents\\GitHub\\ubung-cpp' \n");
	fprintf(gnu, "set key top left \n");
	fprintf(gnu, "set xlabel 'x' \n");
	fprintf(gnu, "set ylabel 'f(x)' \n");
	fprintf(gnu, "plot 'a17-interpol-res.dat' title 'neue Werte' lt rgb 'blue','a16-interpol.dat' title 'alte Werte' lt rgb 'red' \n");
	_pclose(gnu);
	
	return 0;
}
