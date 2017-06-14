/*
 * Programmieren fuer Physiker, SS 2017, Blatt 8, Aufgabe 20
 *
 * Struct fuer Rechteck
 */

#include <iostream>
using namespace std ;

// zu ergaenzen: struct rechteck und zwei Funktionen

struct rechteck{																					// Rechteckstrucktur
	double x;
	double y;
};

rechteck rotation(rechteck r){																		// Rotation
	double swap = r.x;
	r.x = r.y;
	r.y = swap;
	return r;
}

bool bedeckt(rechteck r1, rechteck r2){																// Bedeckt
	if(r1.x>=r2.x and r1.y>=r2.y){
		return 1;
	}
	return 0;
}

int main()																							// Gegebene Programm
{
    cout << "Rechteckstuct" << endl ;
    rechteck r1 = {3.3, 2.0} ;
    rechteck r2 = {1.8, 2.7} ;
    
    cout << "Vor Rotation: " ;
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;

    r2 = rotation(r2) ;

    cout << "Nach Rotation: " ;
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;
}
