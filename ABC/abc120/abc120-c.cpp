#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int N;
stack<int> st;
queue<int> qe;

int ff(int sss[], int k)
{
    if (k == N)
    {
        return N - st.size();
    }
    if (st.size() == 0)
    {
        st.push(sss[k]);
        return ff( sss, k + 1);
    }
    else if (st.top() != sss[k])
    {
        st.pop();
        return ff( sss, k + 1);
    }
    else
    {
        st.push(sss[k]);
        return ff( sss, k + 1);
    }
}
int main()
{
    string S;
    cin >> S;
    N = S.length();
    int SS[N];

    for (int i = 0; i < N; i++)
    {
        SS[i] = (int)S[i];
    }

    st.push(SS[0]);
    cout << ff( SS, 1) << endl;
}
