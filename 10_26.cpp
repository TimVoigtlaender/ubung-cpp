#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std ;

void ausgabe(int anz,int *x){
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

int  free (int testcollum, int testrow, int anz, int *x){
  	for (int test=0; test<testrow; test++)
    	if ((x[test]==testcollum) || (abs(x[test]-testcollum)==abs(test-testrow))) return 0;
  return 1;
}


void setqueen(int row,int &count,int anz,int *x){
	if (row== anz){
		count++;
// 		ausgabe(anz, x);
//		system ("PAUSE");
	}
	else{
	   	for (int i=0; i< anz; i++){
    		if ( free(i,row, anz, x)) {
        x[row]=i;
        setqueen(row+1, count, anz, x);
      		}	
      	}
  	}
}

int main (){
	int anz;
	int count=0;
	cout << "Wie gross ist das Feld?" << endl;
	cin >> anz;
	int x[anz];
	setqueen(0, count, anz, x);
	cout << "Es existieren " << count << " Moeglichkeiten die Damen aufs Feld zu stellen."<< endl; 
	return 0;
}
