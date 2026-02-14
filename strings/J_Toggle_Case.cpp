#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    string s2 = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s2 += (char)(s[i] - 32);
        else s2 += (char)(s[i] + 32);
    }

    cout << s2;
}