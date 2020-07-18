#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <string>
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
    long long N, M;
    string s;
    cin >> N >> M >> s;
    reverse(s.begin(), s.end());
    vector<int> ma(N + 1);
    ma[0] = 0;
    rep(i, 1, N + 1) {
        if(s[i] == '0') {
            ma[i] = i;
        } else {
            ma[i] = ma[i - 1];
        }
    }
    vector<int> res;
    int t = 0;
    while(true) {
        if(t + M >= N) {
            res.push_back(N - t);
            break;
        }
        if(ma[t+M]==t){
            cout<<-1<<endl;
            return 0;
        }
        res.push_back(ma[t + M] - t);
        t = ma[t + M];
    }
    reverse(res.begin(), res.end());
    rep(i, 0, res.size()) {
        if(i != res.size() - 1) {
            cout << res[i] << " ";
        } else {
            cout << res[i] << endl;
        }
    }
}