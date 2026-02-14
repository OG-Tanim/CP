#include <iostream>
// #include <algorithm>
using namespace std;



int main() {
    string s;
    getline(cin, s);

    //remove multiple instances or a character
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    cout << s;
    cout << endl;
}