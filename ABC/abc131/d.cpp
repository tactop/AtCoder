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
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}
int main() {
    int N;
    cin >> N;
    vector<pair<int, long long>> AB;
    rep(i, 0, N) {
        pair<int, long long> p;
        int a;
        long long b;
        cin >> a >> b;
        p.first = a;
        p.second = b;
        AB.push_back(p);
    }

    sort(AB.begin(), AB.end(), compare_by_b);
    long long T = 0;
    string res = "Yes";
    rep(i, 0, N) {
        // cout << AB[i].first<<","<<AB[i].second << endl;
        T += AB[i].first;
        if(T > AB[i].second) {
            res = "No";
            break;
        }
    }
    cout << res << endl;
}