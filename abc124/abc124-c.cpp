#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, x, n) for (int i = x; i < n; i++)
int main()
{
    int N=1;
    cin >> N;
    int H[1000000];
    int ryo = 0;
    int max = 0;
    rep(i, 0, N) { cin >> H[i]; }
    rep(i, 0, N)
    {
        if (H[i] < max)
        {
           
        }
        else if (max < H[i])
        {
            max = H[i];
            ryo++;
        }
        else
        {
            ryo++;
        }
    }
    cout << ryo << endl;
}