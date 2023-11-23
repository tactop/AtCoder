#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
int d[510][510];
int c[510][510];
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    vector<long long> rui(N);
    vector<long long> xrui(N);
    rui[0] = A[0];
    xrui[0] = A[0];
    rep(i, 1, N) {
        rui[i] = rui[i - 1] + A[i];
        xrui[i] = xrui[i - 1] ^ A[i];
    }
    int count = 0;
    rep(l, 0, N) {
        rep(r, l, l + 25) {
            if(r >= N) {
                break;
            }
            long long wa = rui[r];
            long long xwa = xrui[r];
            if(l != 0) {
                wa -= rui[l - 1];
                xwa ^= xrui[l - 1];
            }
            if(wa == xwa) {
                count++;
            } else {
                break;
            }
        }
    }
    cout << count << endl;
}
