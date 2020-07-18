#include <iostream>
using namespace std;
int main()
{
    int A, B, K;
    cin >> A >> B >> K;
    int count = 0;
    int res;
    for (int i = 100; i > 0; --i)
    {
        if (A % i == 0 && B % i == 0)
        {
            count++;
            if (count == K)
            {
                res=i;
                break;
            }
        }
    }
    cout << res << endl;
}