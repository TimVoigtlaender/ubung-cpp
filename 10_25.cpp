#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std ;

class normal_generator{
	public:
		normal_generator() {z1=-1; z2=-1;count=1;}
		double get();
	private:
		double z1,z2;
		int count;
};

double normal_generator::get(){
//	cout <<count <<endl;
	if(count==1){
		double v1 = 2.0*rand()/(double)RAND_MAX - 1;
		double v2 = 2.0*rand()/(double)RAND_MAX - 1;
		double s = pow(v1,2)+pow(v2,2);
//		cout << "s=" << s << endl;
		if(s!=0 and s<1){
			z1 = v1*sqrt(-2*log(s)/s);
			z2 = v2*sqrt(-2*log(s)/s);
//			cout << z1 <<" a "<< z2 << endl;
			count = 2;
			return z1;
		}
		else{
			return get();
		}
	}
	else{
		count = 1;
		return z2;
	}
}

double mittelwert(double *x,int anz){
	double wertm=0;
	for(int i=0; i<anz; i++){
		wertm += x[i];
	}
	return wertm/anz;
}

double standartabw(double *x,int anz,double mid){
	double werts=0;
	for(int j=0; j<anz; j++){
		werts += pow(x[j],2);
	}
	return sqrt((werts-pow(mid,2))/anz);
}

int main() {
	srand((unsigned int)time(0));
	normal_generator gen1, gen2;
	int anz = 100000, einsig=0, zweisig=0, dreisig=0;
	double x[anz], y[anz], sig;
	for(int i=0;i<anz;i++){
		x[i] = gen1.get();
		y[i] = gen2.get();
	}
	sig = standartabw(x,anz,mittelwert(x,anz));
	for(int i=0; i<anz; i++){
		if(abs(y[i])>sig){
			einsig++;
			if(abs(y[i])>2*sig){
				zweisig++;
				if(abs(y[i])>3*sig){
					dreisig++;
				}
			}
		}
	}
	
	
	cout << "Mittelwert = " << mittelwert(x,anz) <<endl;
	cout << "Standartabweichung = " << standartabw(x,anz,mittelwert(x,anz)) << endl;
	cout << "Anzahl Werte (von " << anz << ") deren Betrag groesser ist als:" << endl 
	<< "Ein Sigma: " << einsig << endl 
	<< "Zwei Sigma: " << zweisig << endl 
	<< "Drei Sigma: " << dreisig;
	return 0;
}
