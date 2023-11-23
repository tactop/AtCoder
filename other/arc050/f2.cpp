#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
// bool operator<(const ipair a, const ipair b) {
//     if(a.first == b.first) {
//         return a.second < b.second;
//     } else {
//         return a.first > b.first;
//     }
// }; //演算子
// bool operator>(const ipair a, const ipair b) {
//         return a.second < b.second;
// };
bool operator>(const pair<int, int> a, const pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}; //演算子オーバーロー
int main() {
    int N, D, A;
    cin >> N >> D >> A;
    vector<pair<int, int>> m(N);
    rep(i, 0, N) {
        cin >> m[i].first;
        cin >> m[i].second;
    }
    //    priority_queue<pair<int, int>, greater<pair<int, int>>> que;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        que;
    rep(i, 0, N) { que.push(m[i]); }
    // sort(m.begin(),m.end());
    int count = 0;
    int tmp = 0;
    int res = 0;
    while(count < N) {
        pair<int, int> p = que.top();
        que.pop();
        cout << "f:" << p.first << "se:" << p.second << endl;
        if(p.second > 0) {
            if(p.second - tmp > 0) {
                int kai = (p.second - tmp + A - 1) / A;
                res += kai;
                cout << "x;" << p.first << "tmp:" << tmp << ",kai:" << kai
                     << endl;
                int d = kai * A;
                tmp += d;
                que.push(make_pair(p.first + D + D, -1 * d));
            }
            count++;
        } else {
            tmp += p.second;
        }
    }
    cout << res << endl;
}
