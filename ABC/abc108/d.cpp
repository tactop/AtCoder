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
    int H, W;
    cin >> H >> W;
    int a[510][510];
    rep(i, 1, H + 1) {
        rep(r, 1, W + 1) { cin >> a[i][r]; }
    }
    vector<vector<int>> ans;
    int n = 0;
    rep(i, 1, H + 1) {
        if(i % 2 == 1) {
            rep(r, 1, W + 1) {
                if(a[i][r] % 2 == 1) {
                    if(r != W) {
                        vector<int> ans1;
                        ans1.push_back(i);
                        ans1.push_back(r);
                        ans1.push_back(i);
                        ans1.push_back(r + 1);
                        ans.push_back(ans1);
                        n++;
                        a[i][r + 1]++;
                    } else {
                        if(i != H) {
                            vector<int> ans1;
                            ans1.push_back(i);
                            ans1.push_back(r);
                            ans1.push_back(i + 1);
                            ans1.push_back(W);
                            ans.push_back(ans1);
                            n++;
                            a[i + 1][W]++;
                        }
                    }
                }
            }
        } else {
            rep(r, 1, W + 1) {
                int t = W - r + 1;
                if(a[i][t] % 2 == 1) {
                    if(t != 1) {
                        vector<int> ans1;
                        ans1.push_back(i);
                        ans1.push_back(t);
                        ans1.push_back(i);
                        ans1.push_back(t - 1);
                        ans.push_back(ans1);
                        n++;
                        a[i][t - 1]++;
                    } else {
                        if(i != H) {
                            vector<int> ans1;
                            ans1.push_back(i);
                            ans1.push_back(t);
                            ans1.push_back(i + 1);
                            ans1.push_back(1);
                            ans.push_back(ans1);
                            n++;
                            a[i + 1][1]++;
                        }
                    }
                }
            }
        }
    }
    cout << n << endl;
    rep(i, 0, n) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " "
             << ans[i][3] << endl;
    }
}