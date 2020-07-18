#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
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
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> n(N + 2);
    rep(i, 0, N) {
        cin >> P[i];
        n[P[i]] = i + 1;
    }
    long long res = 0LL;
    multiset<int> se; //今見てるやつより大きい数字のindex
    se.insert(0);
    se.insert(0);
    se.insert(N + 1);
    se.insert(N + 1);
    rep(i, 0, N) {
        int t = N - i;
        int p = n[t];
        auto ite = se.lower_bound(p);
        int mae1, mae2, ato1, ato2;
        ++ite;
        ato2 = *ite;
        --ite;
        ato1 = *ite;
        --ite;
        mae2 = *ite;
        --ite;
        mae1 = *ite;
        se.insert(p);
        // cout << "t:" << t << ",p:" << p << ",mae1:" << mae1 << ",mae2:" <<
        // mae2
        //      << ",ato1:" << ato1 << ",ato2:" << ato2 << ",res+="
        //      << (((mae2 - mae1) * (ato1 - p)) + ((p - mae2) * (ato2 - ato1)))
        //      *
        //             t
        //      << endl;
        res += 1LL *
               (((mae2 - mae1) * (ato1 - p)) + ((p - mae2) * (ato2 - ato1))) *
               t;
    }
    cout << res << endl;
}