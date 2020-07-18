#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int m = max({A, B, C});
    cout << A + B + C - m + 10 * m << endl;
}