#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <type_traits>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    long long AtoB = B - A + 1;
    // cで割れる数
    long long cc = B / C - (A - 1) / C;
    // cで割れない数
    long long cn = AtoB - cc;
    // dで割れる数
    long long dc = B / D - (A - 1) / D;
    // dで割れない数
    long long dn = AtoB - dc;
    // c,dの最小公倍数e
    long long e = LCM(C, D);
    // eで割れる数
    long long ec = B / e - (A - 1) / e;
    // dで割れない数
    long long en = AtoB - ec;
    cout << AtoB - cc - dc + ec << endl;
}