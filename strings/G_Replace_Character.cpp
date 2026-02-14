#include <iostream>
using namespace std;

int main() {
    string s1;
    cin >> s1;

    char a, b;
    cin >> a >> b;

    string s2 = "";

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == a) {
            s2 += b;
        }
        else s2 += s1[i];
    }

    cout << s2;
}
