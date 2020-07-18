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
    cout << max({A + B, A - B, A * B}) << endl;
}