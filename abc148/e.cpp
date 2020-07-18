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

int main() {
    long long N;
    cin >> N;
    if(N % 2 == 1) {
        cout << 0 << endl;
    } else {
        long long res = 0;
        long long nten = N;
        rep(i, 1, 19) {
            res += (nten / 10);
            nten = nten / 10;
        }
        long long nf = N;
        rep(i, 1, 19) {
            res += (nf / 50)-(nf / 100);
            nf = nf / 50;
        }

        cout << res << endl;
    }
}
