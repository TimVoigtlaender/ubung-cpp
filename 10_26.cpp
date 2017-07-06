#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std ;


int anz = 25;
/* x[i] = x coordinate of queen in row i. */

void ausgabe(int *x){
	cout << "+";
	for(int i=0; i<anz;i++){
		cout << "---+";
	}
	cout << endl;
  	for (int row=0; row< anz; row++) {
    	cout << "|";
	    for (int collum=0; collum< anz; collum++){
	      	if (collum==x[row]){
	      		cout << "[ ]";
	      	}
	     	else{
	     		cout << "   ";
	     	}
	     	cout << "|";
	    }
	  	cout << endl << "+";
		for(int i=0; i<anz;i++){
			cout << "---+";
		}
		cout << endl;
	}
 	cout << endl;
}

int  free (int testcollum, int testrow, int *x){
  	for (int test=0; test<testrow; test++)
    	if ((x[test]==testcollum) || (abs(x[test]-testcollum)==abs(test-testrow))) return 0;
  return 1;
}


void setqueen(int row, long int &count, int *x){
	if (row== anz){
  		count++;
  		ausgabe(x);
		system ("PAUSE");
	}
	else{
	   	for (int i=0; i< anz; i++){
    		if ( free(i,row, x)) {
        x[row]=i;
        setqueen(row+1, count, x);
      		}	
      	}
  	}
}

int main (){
	int x[anz];
	long int count=0;
	setqueen(0, count, x);
	cout << "Anzahl moeglichkeiten: " << count << endl << endl;
	return 0;
}
