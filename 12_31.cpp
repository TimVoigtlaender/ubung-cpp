/*
 * Programmieren fuer Physiker, WS 2009/10. Blatt 13, Aufg. 33
 *
 * Binaerer Baum (der sortiert ist): 
 * Einfuegen in Baum. Mimimum feststellen. Alles sortiert ausgeben.
 * (Destruktor)
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std ;

class Node {

private:
    double value ;  // Wert des Knoten
    Node* left ;    // Zeiger auf linken Ast
    Node* right ;   // Zeiger auf rechten Ast

public:
    Node(double x) { value=x ; left=0; right=0 ; } ; // Konstruktor
    void insert(double x) ;
    double min() ;
    double min_v2() ;
    friend ostream & operator<< (ostream & str, const Node & n) ;
} ;

void Node::insert( double x) 
{
    if (x <= value){             
		if (left==0){             
		    left=new Node (x) ;   
		}
		else{
		    (*left).insert(x) ;   
		}
	}
    else{                        
		if (right==0){      
		    right=new Node (x) ;  
		}
		else{
		    (*right).insert(x) ;  
		}
	}
    return ;
}
    
double Node::min(){
    Node* Aktuell=this ;
    while (0 != (*Aktuell).left) Aktuell=(*Aktuell).left ;{
	    return (*Aktuell).value ;
	}
}

double Node::min_v2(){
    if (0 == left){
		return value ;
	}
    else{
		return (*left).min_v2() ;   
	}
}

ostream & operator<< (ostream & str, const Node & n){
    if (0 != n.left) str << *(n.left) ;{
	    str << n.value << " " ;
	}
    if (0 != n.right) str << *(n.right) ;{
	    return str ;
	}
}
    
int main()
{
    srand ((unsigned int)time(0)) ;
    Node tree(1.0) ; // Start
    for(int i=0; i<10; i++){
		double x = 2.0*double(rand())/RAND_MAX ;
		cout << "Einzufuegen: " << x << endl ;
		tree.insert(x) ;
    }
    cout << "Die minimale Zahl im Baum ist: " << tree.min() << endl ;
    cout << "Die minimale Zahl im Baum ist: " << tree.min_v2() << endl ;
    cout << "Alle Eintraege sortiert: " << endl << "  " << tree << endl ;
}
