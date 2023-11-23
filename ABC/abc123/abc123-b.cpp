#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int A[5];
    cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];

    int aa[5];
    for (int i = 0; i < 5; i++)
    {
        aa[i] = A[i] % 10;
    }
    int min = 0;
    for (int i = 1; i < 10; i++)
    {
        if (aa[0] == i || aa[1] == i || aa[2] == i || aa[3] == i || aa[4] == i)
        {
            min = i;
            break;
        }
    }
    //cout<<min<<endl;
    int sum = 0;
    if (min == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            sum += A[i];
        }
        cout << sum << endl;
        return 0;
    }
    for (int i = 0; i < 5; i++)
    {
        sum += A[i];
        if(aa[i]!=0)
        {
            sum += (10 - aa[i]);
        }
    }

    cout << sum - 10 + min << endl;
}