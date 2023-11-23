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
    cin>>S>>Q;
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
            if(henko == 1) {
                a.push_back(1);
            } else {
                a.push_back(0);
            }
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
            if(henko == 0) {
                henko = 1;
            } else {
                henko = 0;
            }
        }
    }
    int tmp = 0;
    rep(i, 0, a.size()) {
        a[i] = (tmp + a[i]) % 2;
        tmp = a[i];
    }

    for(auto p : li) {
        if(p == -1) {

            if(tmp == 0) {
                cout << S;
            } else {
                reverse(S.begin(), S.end());
                cout << S;
            }
        } else {
            string out = cve[p];
            if(a[p] == 0) {
                cout << out;
            } else {
                reverse(out.begin(), out.end());
                cout << out;
            }
        }
    }
    cout << endl;
}
