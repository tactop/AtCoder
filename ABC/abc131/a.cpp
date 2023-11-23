#include <iostream>
#include <string>

using namespace std;
int main() {
    string S;
    cin >> S;
    if(S[0] == S[1] || S[1] == S[2] || S[2] == S[3]) {
        cout << "Bad" << endl;
    } else {
        cout << "Good" << endl;
    }
}