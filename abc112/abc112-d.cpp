#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
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
const int MOD = 1000000007;
long long ruijo(int x, int n) {
    long long res = 1;
    rep(i, 0, n) { res *= x; }
    return res;
}
//約数を列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}
int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> yaku = divisor(M);
    long long max = 0;
    rep(i, 0, yaku.size()) {
        if(M / yaku[i] >= N) {
            chmax(max, yaku[i]);
        }
    }
    cout << max << endl;
}