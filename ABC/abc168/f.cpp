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
int Nokaburi(string t, int k1, int k2) {
    if(t == "AB") {
        if(k1 == 0 || k1 == 1) {
            return k1;
        } else if(k2 == 0 || k2 == 1) {
            return k2;
        }
    } else if(t == "BC") {
        if(k1 == 1 || k1 == 2) {
            return k1;
        } else if(k2 == 1 || k2 == 2) {
            return k2;
        }
    } else {
        if(k1 == 0 || k1 == 2) {
            return k1;
        } else if(k2 == 0 || k2 == 2) {
            return k2;
        }
    }
    return k1;
}
string out(int n) {
    if(n == 0) {
        return "A";
    } else if(n == 1) {
        return "B";
    } else {
        return "C";
    }
}
int main() {
    int N;
    long long a, b, c;
    cin >> N >> a >> b >> c;
    vector<string> q(N);
    rep(i, 0, N) { cin >> q[i]; }
    vector<string> res(N);
    vector<int> t(3);
    t[0] = a;
    t[1] = b;
    t[2] = c;

    rep(i, 0, N) {
        int k1, k2, k3;
        int pl = 0;
        int mi = 0;
        if(q[i] == "AB") {
            k1 = 0;
            k2 = 1;
            k3 = 2;
        } else if(q[i] == "BC") {
            k1 = 1;
            k2 = 2;
            k3 = 0;
        } else {
            k1 = 0;
            k2 = 2;
            k3 = 1;
        }
        if(t[k1] == t[k2] && t[k1] == 0) {
            cout << "No" << endl;
            return 0;
        }
        if(t[k1] == 0) {
            pl = k1;
            mi = k2;
        } else if(t[k2] == 0) {
            pl = k2;
            mi = k1;
        } else {
            if(t[k1] == 1 && t[k2] == 1) {
                if(i != N - 1) {
                    pl = Nokaburi(q[i + 1], k1, k2);
                    if(k1 == pl) {
                        mi = k2;
                    } else {
                        mi = k1;
                    }
                } else {
                    pl = k1;
                    mi = k2;
                }
            } else if(t[k1] == 1) {
                pl = k1;
                mi = k2;
            } else if(t[k2] == 1) {
                pl = k2;
                mi = k1;
            } else {
                pl = k1;
                mi = k2;
            }
        }
        t[pl]++;
        t[mi]--;
        // cout << out(pl) << endl;
        // cout << t[0] << "," << t[1] << "," << t[2] << endl;
        res[i] = out(pl);
    }
    cout << "Yes" << endl;
    rep(i, 0, N) { cout << res[i] << endl; }
}
