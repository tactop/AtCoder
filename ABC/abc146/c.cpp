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
    long long A, B, X;
    cin >> A >> B >> X;
    long long max = 1;
    rep(i, 0, 10) {
        long long aa = A * pow(10, i);
        long long bb = B * (i + 1);
        if(aa + bb <= X) {
            max = i + 1;
        }else{
            break;
        }
    }
    if(max == 10) {
        cout << 1000000000 << endl;
    } else {
        long long res = (X - B * (max)) / A;
        if(res < 0) {
            cout << 0 << endl;

        } else if(res >= pow(10, max)) {
            cout << pow(10, max) - 1 << endl;
        } else {
            cout << res << endl;
        }
    }
}
