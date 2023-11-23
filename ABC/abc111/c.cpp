#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
#include <unordered_map>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
bool compare_by_a(pair<int, long long> a, pair<int, long long> b) {
    if(a.first != b.first) {
        return a.first > b.first;
    } else {
        return a.second < b.second;
    }
}
vector<pair<int, int>> ap(vector<int> ve) {
    vector<pair<int, int>> res;
    unordered_map<int, int> st;
    rep(i, 0, ve.size()) {
        int p = ve[i];
        auto itr = st.find(p);
        if(itr != st.end()) {
            st[p]++;
        } else {
            st.emplace(p, 1);
        }
    }
    st.emplace(0, 0);
    for(auto itr = st.begin(); itr != st.end(); ++itr) {
        pair<int, int> p;
        p.first = itr->second;
        p.second = itr->first;
        res.push_back(p);
    }
    sort(res.begin(), res.end(), compare_by_a);
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> ki;
    vector<int> gu;
    rep(i, 1, n + 1) {
        int a;
        cin >> a;
        if(i % 2 == 1) {
            ki.push_back(a);
        } else {
            gu.push_back(a);
        }
    }
    vector<pair<int, int>> apki;
    vector<pair<int, int>> apgu;
    apki = ap(ki);
    apgu = ap(gu);
    if(apki[0].second != apgu[0].second) {
        cout << n - apki[0].first - apgu[0].first << endl;
    } else {
        int res = min(n - apki[1].first - apgu[0].first,
                      n - apki[0].first - apgu[1].first);
        cout << res << endl;
    }
}