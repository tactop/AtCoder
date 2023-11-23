#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main() {
    long long N, D, A;
    cin >> N >> D >> A;
    vector<pair<long long, long long>> v(N);
    rep(i, 0, N) { cin >> v[i].first >> v[i].second; }
    sort(v.begin(), v.end());
    long long tmp = 0;
    long long count = 0;
    queue<pair<long long, long long>> q;
    rep(i, 0, N) {
        while(q.size() > 0) {
            pair<long long, long long> p = q.front();
            if(p.second < v[i].first) {
                tmp -= p.first;
                q.pop();
                // cout << "pop" << endl;
            } else {
                break;
            }
        }
        // cout << "f" << v[i].first << ",s:" << v[i].second << "," << tmp <<
        // endl;
        if(v[i].second - tmp > 0) {
            // cout << "in" << endl;
            long long kai = (v[i].second - tmp + A - 1) / A;
            long long d = kai * A;
            q.push(make_pair(d, v[i].first + D + D));
            // cout << "qpush:" << d << "," << v[i].first + D + D << endl;
            tmp += d;
            count += kai;
        }
    }
    cout << count << endl;
}