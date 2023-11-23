#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
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
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    vector<long long> rui(N + 1);
    rep(i, 1, N + 1) { rui[i] = rui[i - 1] + A[i - 1]; }
    map<long long, long long> m;
    m[rui[0] - 0] = 1;
    long long res = 0;
    rep(i, 1, N + 1) {
        long long t = (rui[i] - i + K) % K;
        res += m[t];
        m[t]++;
        if(i >= K - 1) {
            long long del = (rui[i - K + 1] - (i - K + 1)) % K;
            m[del]--;
        }
    }
    cout << res << endl;
}