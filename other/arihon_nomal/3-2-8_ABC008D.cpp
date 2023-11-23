#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
#define vein(v, n)                                                             \
    v.assign(n, 0);                                                            \
    for(int i = 0; i < n; i++) {                                               \
        cin >> v[i];                                                           \
    }
using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, pair<int, int>> pp;
const long long INF = 1LL << 60;

int W, H, N;
vector<int> x;
vector<int> y;
}
//座標圧縮
int compress(vector<int> &ve1, vector<int> &ve2, int W) {
    vector<int> ves;
    rep(i, 0, n) {
        ves.push_back(ve1[i]);
        if(ve1[i] > 0) {
            ves.push_back(ve1[i] - 1);
        }
        ves.push_back(ve2[i] - 1);
        if(ve2[i] < W) {
            ves.push_back(ve2[i]);
        }
    }
    sort(ves.begin(), ves.end());
    ves.erase(unique(ves.begin(), ves.end()), ves.end());
    rep(i, 0, n) {
        ve1[i] = lower_bound(ves.begin(), ves.end(), ve1[i]) - ves.begin();
        ve2[i] = lower_bound(ves.begin(), ves.end(), ve2[i]) - ves.begin();
    }
    return ves.size();
}
int main() {
    cin >> W >> H >> N;
    x.assign(N, 0);
    y.assign(N, 0);
    rep(i,0,N){
        cin>>x[i]>>y[i];
    }
    
}
