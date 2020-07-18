#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int N;
stack<int> st;
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
     int del=0;
    for (int i = 1; i < N; i++)
    {
        if(st.size()==0 ||st.top()==SS[i]){
            st.push(SS[i]);
        }
        else{
            st.pop();
            del+=2;
        }
    }

    cout << del << endl;
}
