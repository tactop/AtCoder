#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N, A, B, C;
int inf = 99999999;
int L[8];
int dfs(int v, int a, int b, int c)
{
    if (v == N)
    {
        if (a > 0 && b > 0 && c > 0)
        {
            return abs(a - A) + abs(b - B) + abs(c - C)-30;
        }
        else
        {
            return inf;
        }
    }
    int ret0 = dfs(v + 1, a, b, c);
    int retA = dfs(v + 1, a + L[v], b, c)+10;
    int retB = dfs(v + 1, a, b + L[v], c)+10;
    int retC = dfs(v + 1, a, b, c + L[v])+10;
    return min({ret0, retA, retB, retC});
}
int main()
{
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    cout << dfs(0, 0, 0, 0) << endl;
}
