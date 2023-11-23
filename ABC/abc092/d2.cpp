#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
int d[510][510];
int c[510][510];
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    long long count = 0;
    int sum = 0;
    int r = 0;
    rep(l, 0, N) {
        while(r < N && ((sum ^ A[r]) == (sum + A[r]))) {
        sum+=A[r];
        r++;
        }
        count+=r-l;
        if(l==r){
            r++;
        }else{
            sum-=A[l];
        }
    }
    cout << count << endl;
}
