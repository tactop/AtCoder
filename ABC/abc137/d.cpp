#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
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

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> ve(N);
    rep(i, 0, N) { cin >> ve[i].first >> ve[i].second; }
    sort(ve.begin(), ve.end(), compare_by_a);
    // rep(i, 0, N) { cout << ve[i].first << "," << ve[i].second << endl; }
    priority_queue<int> q;
    int r = 0;
    long long ans = 0;
    rep(i, 0, M + 1) {
        rep(t, r, N) {
            if(ve[t].first <= i) {
                q.push(ve[t].second);
                // cout << "day:" << i << "canwork:" << ve[t].second << endl;
                r++;
            } else {
                break;
            }
        }
        if(q.size() != 0) {
            //      cout << "day:" << i << "work:" << q.top() << endl;
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
}