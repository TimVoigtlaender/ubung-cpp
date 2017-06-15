/*
 * Programmieren fuer Physiker, SS 2017, Blatt 8, Aufgabe 19
 *
 * Permutationen in lexikographischer Ordnung generieren
 * (Fragment, zu ergaenzen)
 */

#include <iostream>
using namespace std ;

// die Funktionen next_permutation (und swap) sind zu ergaenzen

void swap(int a, int b){																							// Funktion swap gebaut
	int sw = a;
	a = b;
	b = sw;
}


bool next_permutation(char *x, int y){																				// Funktion next_permutation gebaut


	int wertk = -1;
	int wertl = -1;
	
	for(int k=0; k<y; k++){																							// P1
		if(x[k]<x[k+1]){
			wertk = k;
		}
	}
	
	if(wertk==-1){																									// 0 falls fertig
		return 0;
	}
	
	for(int l=0; l<y; l++){																							// P2
		if(x[wertk]<x[l]){
			wertl = l;
		}
	}
	
	swap(x[wertk], x[wertl]);																						// P3

	for(int j=wertk+1; j<=(y+wertk)/2; j++){																		// P4
	}

	return 1;
	
	
}

int main()																											// Gegebenes Programm
{
    // Beispieldatensatz, muss sortiert vorliegen
    const int size=6 ;
    char wort[size] = {'A','E','E','F','F','K'} ;

    cout << "Generierung aller Permutationen" << endl << endl ;

    // Hauptschleife, erzeuge alle Permutationen
    int anzperm = 0 ;      // zaehle die Permutationen
    do
    {
	++anzperm ;
	cout << "Nr: " << anzperm << "  " ;
	for( int i=0; i<size; i++)
	    cout << wort[i] << " " ;
	cout << endl ;
    }
    while (next_permutation(wort, size))  ;

    cout << "Anzahl der Permutationen: " << anzperm << endl ;
}
