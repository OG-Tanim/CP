#include <iostream>;
#include <vector>;
using namespace std;

void solve() {
    string s;
    cin >> s;

    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - 48;          //convert each character into their Number equivalents 
    }

    cout << sum;

}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}