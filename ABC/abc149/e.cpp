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
long long N, M;
vector<long long> A;
vector<long long> rui;
vector<long long> ruirui;
bool isOK(long long x) {
    int sum = 0;
    rep(i, 0, N) {
        int nokori = x - A[i];
        sum += rui[max(0, nokori)];
    }
    if(sum < M) {
        return true;
    } else {
        return false;
    }
}

// 汎用的な二分探索のテンプレ
long long binary_search() {
    long long left =
        0LL; //「index = 0」が条件を満たすこともあるので、初期値は -1
    long long right =
        200050; // 「index =
                // a.size()-1」が条件を満たさないこともあるので、初期値は
                // a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 1) {
        long long mid = left + (right - left) / 2;

        if(isOK(mid))
            right = mid;
        else
            left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている
     */
    return left;
}
int main() {
    cin >> N >> M;
    A.assign(N, 0);
    rui.assign(200050, 0);
    ruirui.assign(200050, 0);
    rep(i, 0, N) {
        cin >> A[i];
        rui[A[i]]++;
        ruirui[A[i]] += A[i];
    }
    rep(i, 1, 200050) {
        int t = 200050 - i - 1;
        rui[t] += rui[t + 1];
        ruirui[t] += ruirui[t + 1];
    }
    sort(A.begin(), A.end(), greater<long long>());

    long long min = binary_search();
    cout << min << endl;
    long long res = 0LL;
    long long s = 0;

    rep(i, 0, N) {
        int nokori = min - A[i];
        int ts = rui[max(0, nokori)];
        cout << "ts" << ts << endl;
        res += 1LL * ts * A[i] + ruirui[max(0, nokori)];
        s += ts;
    }
    if(s > M) {
        cout << "over" << endl;
        res -= 1LL * (s - M) * min;
    }
    cout << res << endl;
}
