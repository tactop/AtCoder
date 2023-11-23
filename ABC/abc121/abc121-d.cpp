#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

long long sumofxorunderA(long long a)
{
    int a4 = a % 4;
    if (a4 == 0)
    {
        return a;
    }
    else if (a4 == 1)
    {
        return 1;
    }
    else if (a4 == 2)
    {
        return a+1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    long long A, B;
    cin >> A >> B;
    long long ans =sumofxorunderA(A-1) ^ sumofxorunderA(B);
    cout << ans<< endl;
}