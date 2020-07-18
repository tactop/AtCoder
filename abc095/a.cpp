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
    int res = 700;
    for(int i = 0; i < 3; i++) {
        if(s[i] == 'o') {
            res += 100;
        }
    }
    cout << res << endl;
}
