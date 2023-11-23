#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;
const double PI = 3.14159265358979323846;
int main() {
    string s, t;
    cin >> s >> t;
    string k = t.substr(0, s.size());
    if(k == s) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
