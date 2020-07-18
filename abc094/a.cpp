#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int A, B, X;
    cin >> A >> B >> X;
    if(A + B >= X && A <= X) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
