#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> A[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int k = 0; k < M; k++)
        {
            sum += A[i][k] * B[k];
        }
        if (sum + C > 0)
        {
            count++;
        }
    }
    cout << count << endl;
}