#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std ;

void swapping(double &a, double &b){
	double swap = a;
	a = b;
	b = swap;
}

void print(double *a, int n)
{
    int i = 0;
    while(i < n){
        cout << a[i] << ",";
        i++;
    }
    cout << "\n";
}

int partition(double *arr, const int left, const int right) {
    const int mid = left + (right - left) / 2;
    const double pivot = arr[mid];
    // move the mid point value to the front.
    swapping(arr[mid],arr[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && arr[i] <= pivot) {
            i++;
        }

        while(i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swapping(arr[i], arr[j]);
        }
    }
    swapping(arr[i - 1],arr[left]);
    return i - 1;
}

void quicksort(double *arr, const int left, const int right, const int sz){

    if (left >= right) {
        return;
    }


    int part = partition(arr, left, right);
//    cout << "QSC:" << left << "," << right << " part=" << part << "\n";
//    print (arr, sz);

    quicksort(arr, left, part - 1, sz);
    quicksort(arr, part + 1, right, sz);
}

int main() {
	srand((unsigned int)time(0));
	int anz = 1000;
    double arr[anz];
    for(int i=0; i<anz; i++){
    	arr[i] = double(rand())/RAND_MAX;
	}
//    print(arr, anz);
    quicksort(arr, 0, anz - 1, anz);
    print(arr, anz);
    return 0;
}
