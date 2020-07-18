#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main() {
    long long X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<long long> p(A);
    vector<long long> q(B);
    vector<long long> r(C);
    vector<long long> use;
    rep(i, 0, A) { cin >> p[i]; }
    rep(i, 0, B) { cin >> q[i]; }
    rep(i, 0, C) { cin >> r[i]; }
    sort(p.begin(), p.end(), greater<long long>());
    sort(q.begin(), q.end(), greater<long long>());
    rep(i, 0, X) { use.push_back(p[i]); }
    rep(i, 0, Y) { use.push_back(q[i]); }
    rep(i, 0, C) { use.push_back(r[i]); }
    sort(use.begin(), use.end(), greater<long long>());
    long long sum = 0;
    rep(i, 0, X + Y) { sum += use[i]; }
    cout << sum << endl;
}
