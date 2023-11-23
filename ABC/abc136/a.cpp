#include <iostream>
#include <string>

using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if((C + B) > A) {
        cout << C - (A - B) << endl;

    } else {
        cout << 0 << endl;
    }
}