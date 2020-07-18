#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
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
    int N, M, Q;
    cin >> N >> M >> Q;
    int LR[510][510];
    vector<pair<int, int>> ques;
    rep(i, 0, M) {
        int L, R;
        cin >> L >> R;
        LR[L][R]++;
    }
    rep(i, 0, Q) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        ques.push_back(p);
    }
    rep(i, 1, N + 1) {
        rep(t, 1, N + 1) { LR[i][t] += LR[i][t - 1]; }
    }
    rep(i, 1, N + 1) {
        rep(t, 1, N + 1) { LR[i][t] += LR[i - 1][t]; }
    }
    rep(i, 0, Q) {
        int L = ques[i].first;
        int R = ques[i].second;
        cout << LR[R][R] + LR[L-1][L-1] - LR[L - 1][R] - LR[R][L - 1] << endl;
    }
}