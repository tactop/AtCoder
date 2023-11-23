#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}
const int ININF = 1000000;
long long longPow(int n) {
    long long res = 1;
    rep(i, 0, n) { res *= 2; }
    return res;
}

int main() {
    long long H;
    cin >> H;
    int c = 0;
    vector<long long> v;
    rep(i, 1, 100) {
        v.push_back(H);
        H /= 2;
        if(H == 0) {
            c = i;
            break;
        }
    }
    long long res = 0;
    rep(i, 0, c) { res += longPow(i); }
    cout << res << endl;
}
