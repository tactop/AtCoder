#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int K;
    int X, Y, Z;
    cin >> X >> Y >> Z >> K;
    vector<long long> A, B, C;
    vector<long long> ans;

    for (int r = 0; r < X; r++)
    {
        long long a;
        cin >> a;
        A.push_back(a);
    }
    for (int r = 0; r < Y; r++)
    {
        long long a;
        cin >> a;
        B.push_back(a);
    }
    for (int r = 0; r < Z; r++)
    {
        long long a;
        cin >> a;
        C.push_back(a);
    }
    sort(A.begin(), A.end(), std::greater<int>());
    sort(B.begin(), B.end(), std::greater<int>());
    sort(C.begin(), C.end(), std::greater<int>());

    long long min=1000000000000;
    for (int ai = 0; ai <X; ai++)
    {
        for (int bi = 0; bi <Y; bi++)
        {
            for (int ci = 0; ci < Z; ci++)
            {
                long long abc=A[ai]+B[bi]+C[ci];
                if(min>abc){
                    ans.push_back(abc);

                }else{

                }
            }
        }
    }
}