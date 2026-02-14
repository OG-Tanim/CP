#include <iostream>
using namespace std;

int main() {

    int n, m;   //integer ranges
    cin >> n >> m;    //integer elements

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j= 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    //iterate through each row to print out min
    for (int i = 0; i < n; i++) {
        int min = arr[i][0];

        //checking through all the elements of the array / row.
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < min) min = arr[i][j];
        }

        cout << min << " ";
    }
}