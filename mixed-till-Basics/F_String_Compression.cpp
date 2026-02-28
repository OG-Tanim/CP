#include <iostream>;
using namespace std;

void solve() {

    string stringIn, stringOut = "";
    cin >> stringIn;

    int i = 0;
    while(i < stringIn.size()) {

        int count = 1;

        for (int j = i + 1; j < stringIn.size(); j++) {
            if (stringIn[j] == stringIn[i]) count++;
            else break; 
        }

        if (count > 1) {
            stringOut = stringOut + stringIn[i] + to_string(count);
        }
        else stringOut += stringIn[i];

        i += count;
    }

    cout << stringOut << endl; 

}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

}