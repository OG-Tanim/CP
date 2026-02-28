#include <bits/stdc++.h>
using namespace std;

int main() {

    // Bubble sort: build sorted array bubbling up the largest to the last position
    // Compare each element with previous elements and shift larger ones right
	int arr[]{4, -2, 5, 6, 30, 53, 53, 56, 3, 18, -2, 20, 27};
	
	int n = sizeof(arr) / sizeof(arr[0]);
	
	//only need to place n - 1 (0 to n - 2) max elements at their respective last position
	for (int i = 0; i < n - 1; i++) { 
	    
	    bool swapped = false;
	    
        for (int j = 0; j < n - i - 1; j++) {
        
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); //this will push the largest element to the last(n - 1 [--])
                swapped = true;
            }
        }
        
        if (!swapped) break; //no swap in one iteration means the rest of the array from last is sorted
        
	    for (int i = 0; i < n; i++) {
	    cout << arr[i] << ", ";
	}
	
	cout << endl;
	}
	
	for (int i = 0; i < n; i++) {
	    cout << arr[i] << ", ";
	}
}
