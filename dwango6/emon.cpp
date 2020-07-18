#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    long long N;
    cin >> N;
    vector<long long> res(N);
    rep(i, 0, N) {
        if(i == 1 || i == 0) {
            res[i] = 1;
        } else {
            res[i] = i * res[i - 2];
        }
    }
    rep(i, 0, N) { cout << "i:" << i << ",res:" << res[i] << endl; }
}
