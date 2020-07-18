#include <iostream>
#include <algorithm>
#include <string>
#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;
int main()
{
    string S;
    cin >> S;
    int H[100010];
    int N = S.length();
    int ki=0;
    int gu=0;
    rep(i, 0, N)
    {
        if (S[i] == '1')
        {
            if(i%2==0){ki++;}
            if(i%2!=0){gu++;}
        }
        else
        {
            if(i%2==0){gu++;}
            if(i%2!=0){ki++;}
        }
    }
    cout<<min(ki,gu)<<endl;
}