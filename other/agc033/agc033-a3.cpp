#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
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
int N;
char hw[1010][1010];

int main() {
    int H, W;
    cin >> H >> W;
    int kosuu = 0;
    set<pair<int, int>> se;

    rep(h, 1, H + 1) {
        rep(w, 1, W + 1) {
            cin >> hw[h][w];
            if(hw[h][w] == '#') {
                kosuu++;

            } else {
                pair<int, int> p;
                p.first = h;
                p.second = w;
                se.insert(p);
            }
        }
    }
    int res = 0;
    while(kosuu < H * W) {
        vector <pair<int, int>> ve;
        //  set<pair<int, int>> se2;
        for(auto itr = se.begin(); itr != se.end();) {
            pair<int, int> tp = *itr;
            int h = tp.first;
            int w = tp.second;
            // cout << "h:" << h << "w:" << w << endl;
            if(hw[h][w] == '.') {
                if(hw[h + 1][w] == '#' || hw[h - 1][w] == '#' ||
                   hw[h][w + 1] == '#' || hw[h][w - 1] == '#') {
                    kosuu++;
                  ve.push_back(tp);
                    itr = se.erase(itr);
                } else {
                    ++itr;
                }
            } else {
                ++itr;
            }
        }

        res++;
        rep(i,0,ve.size()){
            hw[ve[i].first][ve[i].second]='#';
        }
        // for(auto itr = se.begin(); itr != se.end();) {
        //     if(hw[*itr.first][*itr.second] == '#') // 偶数ならば
        //         itr = st.erase(itr);               //  削除
        //     else
        //         ++itr;
        // }
        // cout << endl;
        // rep(h, 1, H + 1) {
        //     rep(w, 1, W + 1) { cout << hw[h][w]; }
        //     cout << endl;
        // }
    }

    cout << res << endl;
}