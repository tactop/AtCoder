#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_left(pair<int, int> a, pair<int, int> b) {

    return a.first - a.second <= b.first - b.second;
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
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> X(N);

    rep(i, 0, N) { cin >> X[i].first >> X[i].second; }
    sort(X.begin(), X.end(), compare_by_left);
    int count = 0;
    int tmp = 0;
    rep(i, 1, N) {
        int le = X[i].first - X[i].second;
        int ri = X[i].first + X[i].second;
        int tl = X[tmp].first - X[tmp].second;
        int tr = X[tmp].first + X[tmp].second;
        if(tr > le) {

            count++;
            if(ri < tr) {
                tmp = i;
            }
        } else {
            tmp = i;
        }
    }
    cout << N - count << endl;
}