#include <algorithm>
#include <bitset>
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
//bit全探索的なDP
int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> a(M);
    vector<int> b(M);
    vector<vector<int>> c(M);
    rep(i, 0, M) {
        cin >> a[i] >> b[i];
        rep(j, 0, b[i]) {
            int inc;
            cin >> inc;
            inc--;
            c[i].push_back(inc);
        }
    }
    int all = 1 << N;
    vector<vector<long long>> dp(N, vector<long long>(all, INF));
    rep(i, 0, M) {
        long long tmp = 0LL;
        rep(t, 0, b[i]) { tmp += (1 << c[i][t]); }
        // cout << bitset<12>(tmp) << endl;
        rep(t, 0, all) { dp[0][tmp] = min(dp[0][tmp], a[i]); }
    }
    rep(k, 0, N - 1) {
        rep(i, 0, M) {
            long long tmp = 0LL;
            rep(t, 0, b[i]) { tmp += (1 << c[i][t]); }
            // cout << bitset<12>(tmp) << endl;
            rep(t, 0, all) {
                dp[k + 1][t | tmp] =
                    1LL *
                    min({dp[k + 1][t | tmp], dp[k][t] + a[i], dp[k][t | tmp]});
            }
        }
    }
    // rep(i, 0, N) {
    //     rep(j, 0, all) { cout << dp[i][j] << " "; }
    //     cout << endl;
    // }
    if(dp[N - 1][all - 1] != INF) {
        cout << dp[N - 1][all - 1] << endl;
    } else {
        cout << -1 << endl;
    }
}