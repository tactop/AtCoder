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
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> ve(M);
    rep(i, 0, M) { cin >> ve[i].first >> ve[i].second; }
    sort(ve.begin(), ve.end(), compare_by_b);

    int tmp = 0;
    int res = 0;
    rep(i, 0, M) {
        if(ve[i].first > tmp) {
            res++;
            tmp = ve[i].second - 1;
        }
    }
    cout << res << endl;
}