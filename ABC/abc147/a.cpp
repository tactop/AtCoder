#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    if(A1 + A2 + A3 > 21) {
        cout << "bust" << endl;
    } else {
        cout << "win" << endl;
    }
}