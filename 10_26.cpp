#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std ;


int anz = 8;
int x[8];/* x[i] = x coordinate of queen in row i. */

void ausgabe(){
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

int  free (int testcollum, int testrow){
  	for (int test=0; test<testrow; test++)
    	if ((x[test]==testcollum) || (abs(x[test]-testcollum)==abs(test-testrow))) return 0;
  return 1;
}


void setqueen(int row){
	if (row== anz){
  		ausgabe();
		system ("PAUSE");
	}
	else{
	   	for (int i=0; i< anz; i++){
    		if ( free(i,row)) {
        x[row]=i;
        setqueen(row+1);
      		}	
      	}
  	}
}

int main (){
	setqueen(0);
	return 0;
}
