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
int N, T;
int dp1[3010][3010];
int dp2[3010][3010];
vector<int> A;
vector<int> B;
int main() {
    cin >> N >> T;

    rep(i, 0, N) {
        int a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    dp1[0][0] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= T - 1; j++) {
            dp1[i][j] = dp1[i - 1][j];
            if(j - A[i - 1] >= 0)
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - A[i - 1]] + B[i - 1]);
        }
    }
    dp2[N + 1][0] = 0;
    for(int i = N; i >= 1; i--) {
        for(int j = 0; j <= T - 1; j++) {
            dp2[i][j] = dp2[i + 1][j];
            if(j - A[i - 1] >= 0)
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - A[i - 1]] + B[i - 1]);
        }
    }
    int res = 0;
    rep(i, 0, N) {
        rep(j, 0, T - 1) {
            res = max(res, dp1[i][j] + dp2[i + 2][T - 1 - j] + B[i]);
        }
    }
    cout << res << endl;
}