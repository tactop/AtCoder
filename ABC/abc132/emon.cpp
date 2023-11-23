#include <iostream>
#include <string>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    if(N == 2) {
        if(K == 0) {
            cout << 1 << endl;
            cout << 1 << " " << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    } else if(K > (N - 1) * (N - 2) / 2) {
        cout << -1 << endl;
    } else {
        int rem = (N - 1) * (N - 2) / 2 - K;
        cout << N - 1 + rem << endl;

        rep(i, 2, N + 1) { cout << 1 << " " << i << endl; }

        rep(i, 2, N + 1) {
            if(rem == 0) {
                break;
            }
            rep(r, i + 1, N + 1) {
                cout << i << " " << r << endl;
                rem--;
                if(rem == 0) {
                    break;
                }
            }
        }
    }
}