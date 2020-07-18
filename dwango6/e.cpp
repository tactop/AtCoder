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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    sort(A.begin(), A.end());

    
}
