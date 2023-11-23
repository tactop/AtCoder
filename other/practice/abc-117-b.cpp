#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int L[110];  // 最大 100 個ですが余裕をもたせます
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> L[i];

    sort(L, L + N, greater<int>());  // a[0:N] を大きい順にソート
    int MaxL=L[0];
    int sumNokori=0;
    for(int i=1;i<N;i++) sumNokori += L[i];
    if(MaxL<sumNokori) cout << "Yes" << endl;
    else cout << "No" << endl;
}