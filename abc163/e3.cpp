#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main() {
    long long N;
    int P;
    string S;
    cin >> N >> P >> S;
    long long res = 0;
    if(P == 2 || P == 5) {
        rep(i, 0, N) {
            int t = S[N - 1 - i] - '0';
            if(t % P == 0) {
                res += N - i;
            }
        }
    } else {
        vector<long long> v(P, 0);
        long long ten = 1;
        long long cur = 0;
        v[0]++;
        rep(i, 0, N) {
            int t = S[N - 1 - i] - '0';
            cur = (cur + i * ten) % P;
        }
    }
    cout << res << endl;
}
