#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int A, B;

    cin >> A >> B;
    if(2 * B > A) {
        cout << 0 << endl;
    } else {
        cout << A - 2 * B << endl;
    }
}