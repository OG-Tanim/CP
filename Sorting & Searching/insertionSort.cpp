#include <bits/stdc++.h>
using namespace std;

int main() {

    // Insetion Sort: build sorted array by inseting elements one by one
    // Compare each element with previous element and shift larger one to the right
	int arr[]{4, -2, 5, 6, 30, 53, 53, 56, 3, 18, -2, 20, 27};
	
	int n = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 1; i < n; i++) {
	    
		for (int j = i; j > 0; j--) {
			
		if (arr[j] < arr[j - 1]) {
		swap(arr[j], arr[j - 1]);
		}
		else break;
		}
	    
	    for (int i = 0; i < n; i++) {
	    cout << arr[i] << ", ";
	}
	
	cout << endl;
	}
	
	for (int i = 0; i < n; i++) {
	    cout << arr[i] << ", ";
	}
}
