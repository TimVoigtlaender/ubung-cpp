#include <iostream>
#include <cmath>
using namespace std;

double (*f)(double);

double f1(double x){
    return cos(x)-x;
}
double f2(double x){
    return exp(x)-pow(x,3);
}
double f3(double x){
    return pow(x,2)-5*x+sin(x)-1;
}

void nullstellen(double &x0, double &x1,int counter){
    counter++;
    double xt=(x0+x1)/2.;
    cout << "Schritt " << counter << ":" << endl << "Das Intervall geht von " << x0 << " bis "<< x1 << endl << "Der Wert fuer f(" << xt << ") ist " << f(xt) << endl;
    if(abs(x0-x1)<0.0001 || abs(f(xt))<0.001){
           cout << endl << "Die Funktion hat eine Nullstelle bei " << xt << "." <<endl;
        return;
    }
    else{
        if(f(x0)*f(x1)>0){
            cout << "Es gibt in diesem Intervall keine Nullstelle" << endl;
            return;
        }
        else if(f(x0)*f(xt)>0){
            nullstellen(xt,x1,counter);
        }
        else if(f(xt)*f(x1)>0){
            nullstellen(x0,xt,counter);
        }
        return;
    }
}

int main()
{
    int nf,counter=0;
    double x0,x1;

    cout << "Welche Funktion?" << endl;
    cin >> nf;
    if(nf==1){
        x0=-10;
        x1=10;
        f=f1;
    }
    else if(nf==2){
        x0=2;
        x1=10;
        f=f2;
    }
    else if(nf==3){
        x0=-5;
        x1=5;
        f=f3;
    }
    else{
        cout << "Gibt es nicht!" << endl;
        return 1;
    }
    nullstellen(x0,x1,counter);

    return 0;
}
