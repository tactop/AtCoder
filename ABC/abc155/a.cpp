#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if((a == b && a != c) || (a == c && a != b) || (b == c && b != a)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}