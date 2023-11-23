#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
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
int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> B(N);
    rep(i, 0, N + 1) { cin >> A[i]; }
    rep(i, 0, N) { cin >> B[i]; }
    long long count = 0;

    rep(i, 0, N) {
        if(A[i] <= B[i]) {
            count += A[i];
            B[i] -= A[i];
            if(A[i + 1] <= B[i]) {
                count += A[i + 1];
                A[i + 1] = 0;
            } else {
                count += B[i];
                A[i + 1] -= B[i];
            }
        } else {
            count += B[i];
        }
    }
    cout<<count<<endl;
}