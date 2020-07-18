#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 50;
const int ININF = 1000000;
using pint = pair<int, int>;
using Edge = pair<long long, pint>; //<cost,<u,v>>の形
vector<Edge> edges;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    rep(i, 0, N) { cin >> a[i]; }
    map<string, long long> ma;
    ma[to_string(-1LL - a[0])] = 1LL;
    long long res = 0LL;
    rep(i, 1, N) {
        long long ind = 1LL * i + 1;
        // cout << i << "," << ma[a[i] - ind]<<endl;
        string key = to_string(a[i] - ind);
        if(ma[key] > 0) {
            res = 1LL * res + ma[key];
            ma[to_string(-ind - a[i])]++;
        } else {
            ma[to_string(-ind - a[i])] = 1LL;
        }
    }

    cout << res << endl;
}
