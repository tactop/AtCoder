#include <iostream>
#include <string>

using namespace std;
int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    if(S[K - 1] == 'A') {
        S[K - 1] = 'a';
    }
    if(S[K - 1] == 'B') {
        S[K - 1] = 'b';
    }
    if(S[K - 1] == 'C') {
        S[K - 1] = 'c';
    }
    cout << S << endl;
}