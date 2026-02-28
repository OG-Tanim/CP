#include <iostream>;
using namespace std;

void solve() {

    string stringIn;
    getline(cin >> ws, stringIn);

    int i = 0, max = 0;
    while(i < stringIn.size()) {

        int count = 0;

        for (int j = i; j < stringIn.size(); j++) {
            if (stringIn[j] != ' ') count++;
            else break; 
        }

        if (count > max) max = count;

        i += count + 1;  //+ 1 for each space in between words
    }

    cout << max << endl; 

}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

}