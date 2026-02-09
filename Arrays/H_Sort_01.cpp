#include <iostream>

using namespace std;

int main() {
    // your code goes here
    int testCases;            
    cin >> testCases;
    
    // loop for each test case 
    for (int i = 1; i <= testCases; i++) {

        //taking the size of the array
        int inputSize;
        cin >> inputSize;
        
        //counting 0s and 1s as they are read 
        int zCount = 0;
        int oCount = 0;

        for (int i = 1; i <= inputSize; i++) {
            int n;
            cin >> n;

            if (n == 1) oCount++;
            if (n == 0) zCount++;
        }
        
        //printng zeros and trailing space + if no 1s and last zero no space using ternary
        for (int i = 1; i <= zCount; i++) {
            cout << 0 << ((i == zCount && oCount == 0) ? "" : " ");
        }

        //printng 1 and trailing space + last no space using ternary
        for (int i = 1; i <= oCount; i++) {
            cout << 1 << ((i == oCount) ? "" : " ");
        }
        
        cout << endl;

    }

}