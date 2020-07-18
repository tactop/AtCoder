#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int N, R;
    cin >> N >> R;
    if(N >= 10) {
        cout << R << endl;
    } else {
        cout << R + (100 * (10 - N)) << endl;
    }
}