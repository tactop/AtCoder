#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<int> que;
    rep(i, 0, N) {
        int p;
        cin >> p;
        que.push(p);
    }
    rep(i, 0, M) {
        int tmp = que.top();
        que.pop();
        que.push(tmp / 2);
    }
    long long res = 0;
    while(!que.empty()) {
        res += que.top();
        que.pop();
    }
    cout << res << endl;
}