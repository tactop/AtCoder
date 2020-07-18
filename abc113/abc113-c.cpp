#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
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
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> Y(M);
    vector<int> P(M);
    rep(i, 0, M) {
        cin >> P[i] >> Y[i];
        --P[i];
    }

    vector<vector<int>> vals(N);
    rep(i, 0, M) vals[P[i]].push_back(Y[i]);
    rep(i, 0, N) {
        sort(vals[i].begin(), vals[i].end());
        //普通はダブリをなくすらしい
        vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
    }

    rep(i, 0, M) {
        int v = P[i];
        printf("%06d", v + 1);
        
        int id = lower_bound(vals[v].begin(), vals[v].end(), Y[i]) - vals[v].begin();
        printf("%06d\n", id + 1);
    }
}