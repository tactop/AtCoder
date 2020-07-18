#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
// const long long INF = 1LL << 60;
const int INF = 1 << 30;

int main() {
    int N;
    string S;
    int Q;
    cin >> N >> S >> Q;
    vector<set<int>> p(26, set<int>({INF}));
    rep(i, 0, N) { p[S[i] - 'a'].insert(i); }
    rep(i, 0, Q) {
        int type;
        cin >> type;
        if(type == 1) {
            int ind;
            char c;
            cin >> ind >> c;
            ind--;
            char mae = S[ind];
            S[ind] = c;
            p[mae - 'a'].erase(ind);
            p[c - 'a'].insert(ind);

        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int res = 0;
            rep(k, 0, 26) {
                if(p[k].empty()) {
                    continue;
                }
                int lid = *p[k].lower_bound(l);
                int rid = *p[k].lower_bound(r + 1);
                if(lid < rid) {
                    res++;
                }
            }
            cout << res << endl;
        }
    }
}
