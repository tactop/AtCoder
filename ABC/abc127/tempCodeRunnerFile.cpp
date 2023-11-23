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
typedef long long ll;
int Q;
vector<ll> a;
vector<ll> b;
vector<int> type;
int main() {
    cin >> Q;
    a.assign(Q, 0);
    b.assign(Q, 0);
    type.assign(Q, 0);
    rep(i, 0, Q) {
        cin >> type[i];
        if(type[i] == 1) {
            cin >> a[i] >> b[i];
        }
    }
    priority_queue<ll> mae;
    priority_queue<ll, vector<ll>, greater<ll>> ato;
    ll bsum = 0;
    ll maesum = 0;
    ll atosum = 0;
    rep(i, 0, Q) {
        if(type[i] == 1) {
            bsum += b[i];
            if(mae.size() > ato.size()) {
                // atoに追加
                int top = mae.top();
                if(a[i] >= top) {
                    ato.push(a[i]);
                    atosum += a[i];
                } else {
                    ato.push(top);
                    atosum += top;
                    maesum -= top;
                    mae.pop();
                    mae.push(a[i]);
                    maesum += a[i];
                }
            } else {
                // maeに追加
                if(mae.empty()) {
                    mae.push(a[i]);
                    maesum += a[i];
                } else {
                    int top = ato.top();
                    if(a[i] <= top) {
                        mae.push(a[i]);
                        maesum += a[i];
                    } else {
                        mae.push(top);
                        maesum += top;
                        atosum -= top;
                        ato.pop();
                        ato.push(a[i]);
                        atosum += a[i];
                    }
                }
            }

        } else {
            long long m = mae.top();
            long long res =
                (m * mae.size() - maesum) - (m * ato.size() - atosum) + bsum;
            cout << m << " " << res << endl;
        }
    }
}
