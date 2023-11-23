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
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    int m = 0;
    int m2 = 0;
    int maxc = 0;
    rep(i, 0, N) {
        if(m < A[i]) {
            if(m > m2) {
                m2 = m;
            }
            m = A[i];

        } else if(m2 < A[i]) {
            m2 = A[i];
        }
    }
    rep(i, 0, N) {
        if(A[i] == m) {
            maxc++;
        }
    }

    if(maxc == 1) {
        rep(i, 0, N) {
            if(A[i] == m) {
                cout << m2 << endl;
            } else {
                cout << m << endl;
            }
        }
    } else {
        rep(i, 0, N) { cout << m << endl; }
    }
}
