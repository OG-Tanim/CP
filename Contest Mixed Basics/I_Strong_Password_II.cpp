    #include <iostream>
    using namespace std;

    void solve() {
        string s;
        cin >> s;

        int arr[4] = {0, 0, 0, 0};

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' & s[i] <= 'z')      arr[0] = 1;
            else if (s[i] >= 'A' & s[i] <= 'Z') arr[1] = 1;
            else if (s[i] >= '0' & s[i] <= '9') arr[2] = 1;
            else                                arr[3] = 1;
        }

        int count = 0;

        for (int i = 0; i < 4; i++) {
            if (arr[i] != 0) count++;
        }
        
        if (count > 3) cout << "Strong";
        else if (count == 3) cout << "Moderate";
        else cout << "Weak";
    }

    int main() {
        int t = 1;
        // cin >> t;

        for (int i = 0; i < t; i++) {
            solve();
        }
    }