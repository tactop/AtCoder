#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    int X[M];
    for (int i = 0; i < M; ++i) cin >> X[i];
    if(N>=M) cout << 0 <<endl;
    else{
        sort(X, X + M);  // 小さい順にソート
        //for (int i = 0; i < M; ++i) cout << X[i];
        int Xd[M-1];
        for (int i = 0; i < M-1; ++i) Xd[i]=X[i+1]-X[i];

        int L=X[M-1]-X[0];
        //cout << L;
        if(N==1)cout << L <<endl;
        else{
            sort(Xd, Xd + M-1, greater<int>());  // 大きい順にソート
            for(int i=0;i<N-1;i++){
                L=L-Xd[i];
            }
            cout << L <<endl;
        }
    }
}