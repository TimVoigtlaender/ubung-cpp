#include <iostream>
#include <math.h>

using namespace std ;

 int ggt(int zaehler, int nenner){																	// Größter gemeinsamer Vielfacher berechnen.
     if(nenner == 0){
     	return zaehler;
     }
     else {
	 	return ggt(nenner, zaehler % nenner);
	}
 }

class Ratio{																						// Klasse Ratio erstellen
	public:
		Ratio() {zaehler=0; nenner=1;}
		void setratio(long int x, long int y) 	{zaehler = x; nenner = y; kurz(); return;}			// Eingabe
		void gibratio()							{cout << "(" << zaehler << "/" << nenner << ")";}	// Graphische Ausgabe
		void gibfrac() 							{cout << zaehler/double(nenner);}					// Ausgabe als frac
		Ratio operator+(Ratio);																		// Operatoren überladen
		Ratio operator-(Ratio);
		Ratio operator*(Ratio);
		Ratio operator/(Ratio);
		Ratio operator-()						{zaehler *= -1; return *this;}
		
	private:
		long int zaehler, nenner;																	
		long int gibzaehler() {return zaehler;}														// Ausgabe als Zahlen
		long int gibnenner() {return nenner;}
		void kurz();																				
};

Ratio Ratio::operator+(Ratio sum){																	// Operator +
	zaehler = zaehler*sum.gibnenner()+sum.gibzaehler()*nenner;
	nenner = nenner*sum.gibnenner();
	kurz();
	return *this;
}

Ratio Ratio::operator-(Ratio minu){																	// Operator -
	zaehler = zaehler*minu.gibnenner()-minu.gibzaehler()*nenner;
	nenner = nenner*minu.gibnenner();
	kurz();
	return *this;	
}

Ratio Ratio::operator*(Ratio mal){																	// Operator *
	zaehler *= mal.gibzaehler();
	nenner *= mal.gibnenner();
	kurz();
	return *this;	
}

Ratio Ratio::operator/(Ratio geteilt){																// Operator /
	zaehler *= geteilt.gibnenner();
	nenner *= geteilt.gibzaehler();
	kurz();
	return *this;	
}

void Ratio::kurz(){																					// Kürzen des Bruchs
	int tmp = abs(ggt(zaehler,nenner));
	zaehler/=tmp;
	nenner/=tmp;
	return;
}

int main() {
Ratio br1, br2, br3, br4, br5, tmp;																	// Eingabe der Brüche
br1.setratio(2, 25);
br2.setratio(7, 5);
br3.setratio(2, 5);
br4.setratio(1, 4);
br5.setratio(1, 3);


br1.gibratio(); cout << " / "; br2.gibratio(); cout << " - "; br3.gibratio(); 						// Graphische Ausgabe des Terms
cout << " * ("; br4.gibratio(); cout << " + "; br5.gibratio(); cout << ") = ";

tmp = br1/br2-br3*(-br4+br5);																		// Berechnen der Lösung
tmp.gibratio();																						// Graphische Ausgabe der Lösung
cout << " = ";
tmp.gibfrac();
cout << endl;
    return 0;
}
