#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size();i++) {
        if(s[i] == '7') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
