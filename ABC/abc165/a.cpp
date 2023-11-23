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
    int a, b, k;
    cin >> k >> a >> b;
    bool res = false;
    for(int i = a; i <= b; i++) {
        if(i % k == 0)
            res = true;
    }
    if(res) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }
}
