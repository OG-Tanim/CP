#include <iostream>
using namespace std;

int countOf1(int arr[], int c) {
    int count = 0;
    for (int i = 0; i < c; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {

    int n, m;   //integer ranges
    cin >> n >> m;    //integer elements

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j= 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int max = countOf1(arr[0], m);  // set max of the first row

    int idx;
    (max == 0) ? idx = -1 : idx = 0;  //if first row has at least 1, set index to 0, else -1.

    for (int i = 1; i < n; i++) {

        int count = countOf1(arr[i], m);   //count of 1s for that row
        if (count > max) {                // checking only greater because only the first instance of max counts
            max = count;                  //update max and index
            idx = i;
        } 
    }

    cout << idx;
   
}