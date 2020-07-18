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
long long longPow(int n) {
    long long res = 1;
    rep(i, 0, n) { res *= 2; }
    return res;
}
int main() {
    int M, K;
    cin >> M >> K;
    long long max = longPow(M) - 1;
    if(M == 0) {
        if(K == 0) {
            cout << "0 0" << endl;
        } else {
            cout << -1 << endl;
        }
    } else if(M == 1) {

        if(K == 0) {
            cout << "0 1 1 0" << endl;
        } else {
            cout << -1 << endl;
        }
    } else if(max < K) {
        cout << -1 << endl;
    } else {

        rep(i, 0, max + 1) {
            if(i != K) {
                cout << i << " ";
            }
        }
        cout << K << " ";
        rep(i, 0, max + 1) {
            int t = max - i;
            if(t != K) {
                cout << t << " ";
            }
        }
        cout << K << endl;
    }
}
