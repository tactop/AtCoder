#include <iostream>
#include <string>

using namespace std;
int main() {
    string S, T;
    cin >> S >> T;

    int res = 0;
    for(int i = 0; i < 3; i++) {
        if(S[i] == T[i]) {
            res++;
        }
    }
    cout << res << endl;
}