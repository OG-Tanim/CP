#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arrIn[n];
    int arrSl[n];

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        arrIn[i] = val;
        arrSl[i] = val; 
    }

    int shifts = 0;
    int swaps = 0;

    //Insertion Sort
    for (int i = 1; i < n; i++) {

        for (int j = i; j > 0; j--) {   

                if (arrIn[j] < arrIn[j - 1]) {
                    swap(arrIn[j], arrIn[j - 1]);
                    shifts++;
                }
                else break;
            }
    }

    //Selection Sort
    for (int i = 0; i < n - 1; i++) {

        int minVal = arrSl[i];
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            
            if (arrSl[j] < minVal) {
                minVal = arrSl[j];
                minIdx = j;
            }
        }

        if (i != minIdx) {
            swap(arrSl[minIdx], arrSl[i]);
            swaps++;
        }
    }

    // cout << "swaps: " << swaps << "; shifts :" << shifts << endl;

    if (swaps == shifts) cout << "Tie";
    else if (swaps < shifts) cout << "Selection Sort";
    else cout << "Insertion Sort";

    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}