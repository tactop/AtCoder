// abc126d(https://atcoder.jp/contests/abc126/tasks/abc126_d)
#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;

int N;
long long K;
vector<int> A;
const long long INF = 1LL << 60;

int main() {
    cin >> N >> K;
    A.assign(N, 0);
    rep(i, 0, N) {
        int t;
        cin >> t;
        t--;
        A[i] = t;
    }
    vector<int> kyori(N, 0);
    int next = 0;
    int tmp = 0;
    while(true) {
        next = A[tmp];
        if(next == 0 || kyori[next] != 0) {
            break;
        } else {
            kyori[next] = kyori[tmp] + 1;
            tmp = next;
            if(kyori[next] == K) {
                cout << next + 1 << endl;
                return 0;
            }
        }
    }
    // rep(i, 0, N) { cout << kyori[i] << endl; }
    int hen = kyori[tmp] - kyori[next] + 1;
    // cout << hen << endl;
    // cout << kyori[next] << endl;
    K = K - kyori[next];

    K = K % hen;
    // cout << K << endl;
    rep(i, 0, N) {
        if(kyori[i] == kyori[next] + K) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}