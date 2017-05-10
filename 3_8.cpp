#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
int zeile[10],zeiletmp[10];
for (int n=0; n<=9; n++){
	for (int m=0; m<=n; m++){						// abspeichern in zeiletmp
		zeiletmp[m] = zeile[m];						
	}
	(zeile[0], zeile[n]) = 1;						// definieren der ersten und der n-sten Stelle von zeile
 for (int k=1; k<=n-1; k++){
		zeile[k] = zeiletmp[k-1]+zeiletmp[k];		// berechnen der übrigen Stellen von zeile
	} 
cout << setw((15-n)*2);								//	einrücken der Pyramide
	for (int m=0; m<=n; m++){
		cout << zeile[m] << setw(4);				// ausgabe der Werte und einrücken der Pyramide
	}
	cout << endl;
}
  return(0);
}
