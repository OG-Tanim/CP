#include <bits/stdc++.h>
using namespace std;

int main() {

	//put the min elem in the righmost position in each iteration
	int arr[]{1, 5, 2, 6, 0};
	int n = 5;

	int swaps = 0;

	for (int i = 0; i < n - 1; i++) {

        int minVal = arr[i];
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            
            if (arr[j] < minVal) {
                minVal = arr[j];
                minIdx = j;
            }
        }

        if (i != minIdx) {
            swap(arr[minIdx], arr[i]);
            swaps++;
        }
    }

	cout << swaps;
	
	cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] ;
}
