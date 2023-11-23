#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}
int main() {
    long long N, K;
    cin >> N >> K;
    int a[100000];
    rep(i, 0, N) { cin >> a[i]; }
    long long rui[100001];
    rui[0] = 0;
    rep(i, 1, N + 1) {
        rui[i] = rui[i - 1] + a[i - 1];
        // cout << rui[i] << endl;
    }

    int r = 0;
    long long count = 0;
    rep(i, 0, N) {
        long long sum = rui[r] - rui[i];
        bool ok = true;
        while(sum < K) {
            r++;
            if(N < r) {
                ok = false;
                // cout << "ir:" << i << "," << r << endl;
                break;
            }
            sum = rui[r] - rui[i];
        }
        if(ok) {
            count += N - r + 1;
        } else {
            break;
        }
    }
    cout << count << endl;
}