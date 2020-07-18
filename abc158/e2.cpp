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
    int N, P;
    cin >> N >> P;
    string s;
    cin >> s;
    long long res = 0;
    if((s[0] - '0') % P == 0) {
        res++;
    }
    list<pair<int, int>> li;
    li.push_front(make_pair(((s[0] - '0') % P), 1));
    // for(auto tl : li) {
    //     cout << tl.first << "," << tl.second << endl;
    // }
    rep(i, 1, N) {
        int si = s[i] - '0';
        list<pair<int, int>> nli;
        bool ari = false;
        for(auto tl : li) {
            int yo = tl.first;
            int ko = tl.second;
            int next = (tl.first * 10 + si) % P;
            if(next == si % P) {
                ko++;
                ari = true;
            }
            if(next == 0) {
                res += ko;
            }
            nli.push_front(make_pair(next, ko));
        }
        if(!ari) {
            nli.push_front(make_pair(si % P, 1));
            if(si % P == 0) {
                res++;
            }
        }
        li = nli;
        // cout << "i:" << i << endl;
        // for(auto tl : li) {
        //     cout << tl.first << "," << tl.second << endl;
        // }
    }
    cout << res << endl;
}
