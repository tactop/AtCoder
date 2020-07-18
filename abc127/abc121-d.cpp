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
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, long long>> AC;
    rep(i, 0, N) {
        pair<int, long long> p;
        long long a;
        cin >> a;
        p.first = 1;
        p.second = a;
        AC.push_back(p);
    }
    rep(i, 0, M) {
        pair<int, long long> p;
        int b;
        long long c;
        cin >> b >> c;
        p.first = b;
        p.second = c;
        AC.push_back(p);
    }
    sort(AC.begin(), AC.end(), compare_by_b);
    int r = 0;
    long long res = 0;
    rep(i, 0, N) {
        int b = AC[i].first;
        long long c = AC[i].second;
        // cout << "i:" << i << ",b:" << b << ",c:" << c << endl;
        if(r + b < N) {
            res += b * c;
            r+=b;
        } else {
            res += (N - r) * c;
            break;
        }
    }
    cout << res << endl;
}