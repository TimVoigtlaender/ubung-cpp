#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std ;


int x[8]; /* x[i] = x coordinate of queen in row i. */

void ausgabe(){
	cout << "+---+---+---+---+---+---+---+---+" << endl;
  	for (int row=0; row< 8; row++) {
    	cout << "|";
	    for (int collum=0; collum< 8; collum++){
	      	if (collum==x[row]){
	      		cout << "[ ]";
	      	}
	     	else{
	     		cout << "   ";
	     	}
	     	cout << "|";
	    }
	  	cout << endl << "+---+---+---+---+---+---+---+---+" << endl;
	}
 	cout << endl;
}

int  free (int testcollum, int testrow)
{
  for (int test=0; test<testrow; test++)
    if ((x[test]==testcollum) || (abs(x[test]-testcollum)==abs(test-testrow))) return 0;
  return 1;
}


void setqueen(int row){
	if (row== 8){
  		ausgabe();
//		system ("PAUSE");
	}
	else{
	   	for (int i=0; i< 8; i++){
    		if ( free(i,row)) {
        x[row]=i;
        setqueen(row+1);
      		}	
      	}
  	}
}

int main ()
{
  setqueen(0);
  return 0;
}
