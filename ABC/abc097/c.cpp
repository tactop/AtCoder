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
    string S;
    int K;
    cin >> S >> K;
    vector<string> v;
    rep(i, 0, S.size()) {
        rep(j, 1, K + 1) {
            string tmp = S.substr(i, j);
            // if(j > S.size()) {
            //     //substrの二番目の引数は範囲外でもいけるのか！
            //     cout << i << "," << j << ",tmp:" << tmp << endl;
            // }
            v.push_back(tmp);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v[K - 1] << endl;
}
