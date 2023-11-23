#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(c - a) <= d) {
        cout << "Yes" << endl;
    } else if(abs(b - a) <= d && abs(b - c) <= d) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

