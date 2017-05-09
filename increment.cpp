#include <cmath>
#include <iostream>
using namespace std;
int i,j,k=1;
float l;
int main(){
	cout << "Zahl? " << endl;
	cin >> l;
	i = l;
	if (i<0 or i!=l){
			cout << "Existiert nicht!" << endl;
	}
		else{
		if (i==0){
			k = 1;
		}
		else{
			for (j = 1 ;j <= i; ++j){
			k = k*j;
			}
		}
	cout << k << endl;
	}
	return(0);
}
