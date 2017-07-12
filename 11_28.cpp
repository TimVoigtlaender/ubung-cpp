#include <iostream>
#include <cmath>
using namespace std;

double f1(double x){
    return cos(x)-x;
}
double f2(double x){
    return exp(x)-pow(x,3);
}
double f3(double x){
    return pow(x,2)-5*x+sin(x)-1;
}

double nullstellen( double (*f)(double), double x0,double x1,double epsx, double epsf){
	double xt;
	if(f(x0)*f(x1)>0){
        cout << "Es gibt in diesem Intervall keine Nullstelle" << endl;
        return 0;
    }
    for(int i=0;abs(x0-x1)>=epsx and abs(f(xt))>=epsf; i++){
    	xt=(x0+x1)/2.;
        cout << "Schritt " << i << ":" << endl << "Das Intervall geht von " << x0 << " bis "<< x1 << endl << "Der Wert fuer f(" << xt << ") ist " << f(xt) << endl;
        if(f(x0)*f(xt)>0){
           x0 = xt;
        }
        else{
           x1 = xt;
        }
    }
    return xt;
}

int main()
{
    int nf;
    double null;
	double epsx=pow(10,-4), epsf=pow(10,-3);
    cout << "Welche Funktion?" << endl;
    cin >> nf;
    if(nf==1){
    	null = nullstellen(f1,-10,10,epsx,epsf);
    }
    else if(nf==2){
    	null = nullstellen(f2, 2,10,epsx,epsf);
    }
    else if(nf==3){
    	null = nullstellen(f3,-5,5,epsx,epsf);
    }
    else{
        cout << "Gibt es nicht!" << endl;
        return 1;
    }
	cout << endl << "Die Funktion f" << nf << "(x) hat eine Nullstelle bei " << null << endl;
    return 0;
}
