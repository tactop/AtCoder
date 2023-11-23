#include <iostream>
#include <string>

using namespace std;
int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    if(A*C<=B){
        cout << C <<endl;
    }else{
        cout << B/A <<endl;
    }
}