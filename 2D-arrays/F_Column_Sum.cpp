#include <iostream>
using namespace std;

int countOf1(int arr[], c) {
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

    int max = countOf1(arr[0]);

    cout << max;

    //iterate through each each column
    for (int j = 0; j < m; j++) {
        int sum = 0;

        //checking through all the rows of each column
        for (int i = 0; i < n; i++) {
            sum += arr[i][j];
        }

        cout << sum << " ";
    }
}