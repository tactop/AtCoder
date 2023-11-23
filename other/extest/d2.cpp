#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
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
int main() {

    string S;
    int Q;
    cin >> S >> Q;
    vector<int> a;
    vector<string> cve;
    bool jun = true;
    list<int> li;
    li.push_front(-1);
    int henko = 0;
    rep(i, 0, Q) {
        int t;
        cin >> t;
        if(t == 2) {
            int f;
            cin >> f;
            string c;
            cin >> c;
            cve.push_back(c);
            if(jun) {
                if(f == 2) {
                    li.push_back((cve.size() - 1));
                } else {
                    li.push_front((cve.size() - 1));
                }
            } else {
                if(f == 1) {
                    li.push_back((cve.size() - 1));
                } else {
                    li.push_front((cve.size() - 1));
                }
            }
        } else {
            if(jun) {
                jun = false;
            } else {
                jun = true;
            }
        }
        // for(auto p : li) {
        //     if(p == -1) {
        //         if(jun) {
        //             cout << S;
        //         } else {
        //             reverse(S.begin(), S.end());
        //             cout << S;
        //         }
        //     } else {
        //         string out = cve[p];

        //         cout << out;
        //     }
        // }
        // cout << endl;
    }
    string res;
    for(auto p : li) {
        if(p == -1) {
            res += S;
            // if(jun) {
            //     cout << S;
            // } else {
            //     reverse(S.begin(), S.end());
            //     cout << S;
            // }
        } else {
            res += cve[p];
        }
    }
    if(!jun) {
        reverse(res.begin(), res.end());
    }
    cout << res << endl;
}
