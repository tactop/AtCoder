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
    int N, K;
    cin >> N >> K;
    vector<vector<long long>> s(N);
    rep(i, 0, N) {
        long long t, d;
        cin >> t >> d;
        s[t - 1].push_back(d);
    }
    for(auto &v : s) {
        sort(v.begin(), v.end(), greater<long long>());
        if(v.empty()) {
            v.push_back(-INF);
        }
    }
    sort(s.begin(), s.end(),
         [&](vector<long long> a, vector<long long> b) { return a[0] > b[0]; });

    long long cur = 0;
    priority_queue<long long> que;
    rep(i, 0, K) {
        cur += s[i][0];
        rep(r, 1, s[i].size()) { que.push(s[i][r]); }
    }
    rep(i, K, N) {
        rep(r, 0, s[i].size()) { que.push(s[i][r]); }
    }
    long long res=cur+K*K;
       for (long long x = K-1; x >= 1; --x) {
        long long v = s[x][0];
        long long w = que.top();
        if (v < w) {
            que.pop(); cur += w;
            que.push(v); cur -= v;
        }
        res = max(res, cur + x*x);
    }
    cout << res << endl;
}
