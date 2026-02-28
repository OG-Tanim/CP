#include <bits/stdc++.h>
using namespace std;

int main() {

    // Insertion sort: build sorted array by inserting elements one by one
    // Compare each element with previous elements and shift larger ones right
	int arr[]{4, -2, 5, 6, 30, 53, 53, 56, 3, 18, -2, 20, 27};
	
	int n = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 1; i < n; i++) {
	    
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
	    
        arr[j + 1] = temp;
        
	    for (int i = 0; i < n; i++) {
	    cout << arr[i] << ", ";
	}
	
	cout << endl;
	}
	
	for (int i = 0; i < n; i++) {
	    cout << arr[i] << ", ";
	}
}
 