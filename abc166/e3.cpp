#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
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
    cin>>N;
    vector<long long> a(N);
    rep(i, 0, N) { cin >> a[i]; }
    multiset<long long> se;
    se.insert(-1 - a[0]);
    long long res = 0LL;
    rep(i, 1, N) {
        int ind = i + 1;
        res += se.count(a[i] - ind);
        se.insert(-ind - a[i]);
    }
 
    cout << res << endl;
}