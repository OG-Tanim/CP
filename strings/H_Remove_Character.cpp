#include <iostream>
using namespace std;

int main() {
    string s1;
    cin >> s1;

    char toRemove;
    cin >> toRemove;

    string s2 = "";

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != toRemove) {
            s2 += s1[i];
        }
    }

    cout << s2;
}

