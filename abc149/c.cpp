#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}

int main() {
    int X;
    cin >> X;

    while(true) {
        bool sosuu = true;
        for(int i = 2; i * i <= X; i++) {
            if(X % i == 0) {
                sosuu = false;
                break;
            }
        }
        if(sosuu) {
            cout << X << endl;
            break;
        }
        X++;
    }
}
