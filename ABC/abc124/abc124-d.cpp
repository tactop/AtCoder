#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<vector<int>> H;
    rep(i, 0, N) { H.push_back({0, 0}); }
    int tmp = S[0] - '0';
    H[0][0] = 1;
    int tmpIdx = 0;
    int ind = 1;
    while (ind < N)
    {
        int si = S[ind] - '0';
        if (tmp == si)
        {
            H[tmpIdx][0]++;
            if (tmp == 1)
            {
                H[tmpIdx][1] = 1;
            }
        }
        else
        {
            H[tmpIdx + 1][0]++;
            if (tmp == 1)
            {
                H[tmpIdx][1] = 1;
            }
            tmpIdx++;
            tmp = si;
        }
        ind++;
    }
    int kukansu = tmpIdx + 1;
    int ruisekiwa[kukansu];
    rep(i, 0, kukansu)
    {
        if (i == 0)
        {
            ruisekiwa[i] = H[i][0];
        }
        else
        {
            ruisekiwa[i] = ruisekiwa[i - 1] + H[i][0];
        }
        //cout << ruisekiwa[i] << endl;
    }
    int kukanlong = 2 * K + 1;
    int max = 0;
    rep(i, 0, kukansu)
    {
        if (kukanlong > kukansu)
        {
            max = ruisekiwa[kukansu - 1];
            break;
        }
        int sum;
        bool henkou = false;
        if (i == 0)
        {
            if (H[0][1] == 0)
            {
                sum = ruisekiwa[kukanlong - 2];
            }
            else
            {
                sum = ruisekiwa[kukanlong - 1];
            }
        }
        else
        {
            if (H[i][1] == 0)
            {
                if (i + kukanlong - 2 > kukansu - 1)
                {
                    sum = ruisekiwa[kukansu - 1] - ruisekiwa[i - 1];
                }
                else
                {
                    sum = ruisekiwa[i + kukanlong - 2] - ruisekiwa[i - 1];
                }
            }
            else
            {
                if (i + kukanlong - 1 > kukansu - 1)
                {
                    sum = ruisekiwa[kukansu - 1] - ruisekiwa[i - 1];
                }
                else
                {
                    sum = ruisekiwa[i + kukanlong - 1] - ruisekiwa[i - 1];
                }
            }
        }
        //cout << "sum:" << sum << endl;
        if (max < sum)
        {
            max = sum;
        }
    }
    cout << max << endl;
}