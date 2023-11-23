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
    if(a + b >= c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
