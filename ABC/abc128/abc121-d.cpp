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
    int N, K;
    cin >> N >> K;
    int V[55];
    long long L[55];
    long long R[55];
    long long max = -INF;
    rep(i, 0, N) { cin >> V[i]; }
    rep(i, 0, N + 1) {

        if(K < i) {
            break;
        }
        rep(l, 0, i + 1) {
            vector<int> get;
            rep(a, 0, l) { get.push_back(V[a]); }
            rep(b, 0, i - l) { get.push_back(V[N - b-1]); }
            sort(get.begin(), get.end());
            int ret = 0;
            int sum = 0;
            rep(c, 0, get.size()) {
                sum += get[c];
                if(ret + i < K) {
                    if(get[c] < 0) {
                        sum -= get[c];
                        ret++;
                    }
                }
            }
            // cout << "i:" << i << ",l:s" << l << ",ret:" << ret << ",sum:" << sum
                //  << endl;
            if(max < sum) {
                max = sum;
            }
        }
    }
    cout << max << endl;
}