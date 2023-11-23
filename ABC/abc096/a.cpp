#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if(a > b) {
        cout << a - 1 << endl;
    } else {
        cout << a << endl;
    }
}
