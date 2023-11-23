#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
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
    string s, t;
    cin >> s >> t;
    int alf = 'z' - 'a' + 1; // 26
    int ns = s.size();
    int nt = t.size();
    string ss = s + s;
    int nss = 2 * s.size();
    vector<vector<int>> v(
        nss + 1, vector<int>(alf, -1)); // i文字目以降で文字がどこで出現するか
    rep(i, 0, nss) {
        int t = nss - i - 1;
        char tmp = ss[t];
        v[t] = v[t + 1];
        v[t][tmp - 'a'] = t;
    }
    // rep(i, 0, nss) {
    //     rep(j, 0, alf) { cout << v[i][j] << " "; }
    //     cout << endl;
    // }
    int ind = 0;
    long long res = 0LL;
    rep(i, 0, nt) {
        int tt = t[i] - 'a';
        if(v[ind][tt] == -1) {
            cout << -1 << endl;
            return 0;
        }
        ind = v[ind][tt] + 1;
        if(ind > ns) {
            ind -= ns;
            res += ns;
        }
    }
    res += ind;
    cout << res << endl;
}