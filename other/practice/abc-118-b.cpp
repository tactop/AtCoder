#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    int food[M] = {};
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        int A[K];
        for (int r=0;r<K;++r){
            cin >> A[r];
            food[A[r]-1]++;
        }
    }
    int res=0;
    for(int i=0;i<M;i++){
        if(food[i]==N){
            res++;
        }
    }
    cout << res <<endl;

}