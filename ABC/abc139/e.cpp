#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
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
bool flg = false;
int ch[1001][1001];
int hi[1001];
vector<queue<int>> A;
void solv(int a, int b) {
    // cout << "in a:" << a << " b:" << b << endl;
    if(ch[a][b] == 1) {
        flg = true;
        return;
    }
    ch[a][b] = 1;
    while(A[b].front() != a) {
        // cout << "in" << endl;
        solv(b, A[b].front());
        if(flg) {
            return;
        }
    }
    int m = max(hi[a], hi[b]);
    hi[a] = m + 1;
    hi[b] = m + 1;
    A[a].pop();
    A[b].pop();
    return;
}
int main() {
    int N;
    cin >> N;
    queue<int> qe;
    A.push_back(qe);
    rep(i, 0, N) {
        queue<int> qe;
        rep(r, 0, N - 1) {
            int a;
            cin >> a;
            qe.push(a);
        }
        A.push_back(qe);
    }
    rep(i, 0, N + 1) { hi[i] = 0; }
    rep(i, 1, N + 1) {
        while(!A[i].empty()) {
            // cout << "while" << endl;
            solv(i, A[i].front());
            if(flg) {
                break;
            }
        }
    }
    if(flg) {
        cout << -1 << endl;
    } else {
        int max = 0;
        // cout << "hi" << endl;
        rep(i, 1, N + 1) {
            // cout << hi[i] << endl;
            if(hi[i] > max) {
                max = hi[i];
            }
        }
        cout << max << endl;
    }
}