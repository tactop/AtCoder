#include <iostream>
#include <string>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;

int main() {
    int M, D;
    cin >> M >> D;
    int count = 0;
    rep(i, 1, M + 1) {
        rep(j, 1, D + 1) {
            if(j % 10 >= 2 && j / 10 >= 2 && (j % 10) * (j / 10) == i) {
                count++;
            }
        }
    }
    cout << count << endl;
}