#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

bool isOK(vector<int> v, int index, int key) {
    if(v[index] > key)
        return true;
    else
        return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(vector<int> v, int key) {
    int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right =
        (int)v.size(); // 「index =
                       // a.size()-1」が条件を満たさないこともあるので、初期値は
                       // a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 1) {
        int mid = left + (right - left) / 2;

        if(isOK(v, mid, key))
            right = mid;
        else
            left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている
     */
    return right;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    vector<int> B(N);
    rep(i, 0, N) { cin >> B[i]; }
    vector<int> C(N);
    rep(i, 0, N) { cin >> C[i]; }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    long long res = 0;
    rep(i, 0, N) {
        long long bc =
            N - distance(C.begin(), lower_bound(C.begin(), C.end(), B[i] + 1));
        long long ab =
            distance(A.begin(), lower_bound(A.begin(), A.end(), B[i]));
        res += bc * ab;
    }
    cout << res << endl;
}
