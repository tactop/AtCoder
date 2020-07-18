#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> AB(N);
    for (int i = 0; i < N; i++)
    {
        long long a, b;
        cin >> a >> b;
        AB[i] = {a, b};
    }
    sort(AB.begin(), AB.end());
    int sumhon = 0;
    long long summoney = 0;
    for (int i = 0; i < N; i++)
    {
        long long Ai = AB[i].first;
        long long Bi = AB[i].second;
        if (sumhon + Bi >= M)
        {
            summoney += (M - sumhon) * Ai;
            break;
        }
        else
        {
            summoney += Ai * Bi;
            sumhon += Bi;
        }
    }
    cout << summoney << endl;
}